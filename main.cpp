// COMSC-210 | Lab 25 | Arkhip Finski
// IDE used: Visual Studio
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <set>
#include <list>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

const string test = "TESTCODE";

int main() {
    ifstream inputFile("codes.txt");
    string code;
    list<string> list;
    set<string> set;
    vector<string> vector;

    if(!inputFile){
        cout << "Failed to open file" << endl;
        return 1;

    }

    //VECTOR

    auto vector_startR = high_resolution_clock::now();
    while(getline(inputFile, code)){
        vector.push_back(code);
    }
    auto vector_endR = high_resolution_clock::now();
    auto vector_durationR = duration_cast<microseconds>(vector_endR - vector_startR);


    auto vector_startS = high_resolution_clock::now();
    sort(vector.begin(), vector.end());
    auto vector_endS = high_resolution_clock::now();
    auto vector_durationS = duration_cast<microseconds>(vector_endS - vector_startS);

    auto vector_startI = high_resolution_clock::now();
    vector.insert(vector.begin() + (vector.size()/2),test);
    auto vector_endI = high_resolution_clock::now();
    auto vector_durationI = duration_cast<microseconds>(vector_endI - vector_startI);

    auto vector_startD = high_resolution_clock::now();
    vector.erase(vector.begin() + ((vector.size()/2)-1));
    auto vector_endD = high_resolution_clock::now();
    auto vector_durationD = duration_cast<microseconds>(vector_endD - vector_startD);

    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    // LIST

    auto list_startR = high_resolution_clock::now();
    while(getline(inputFile,code)){
        list.push_back(code);
    }
    auto list_endR = high_resolution_clock::now();
    auto list_durationR = duration_cast<microseconds>(list_endR - list_startR);

    auto list_startS = high_resolution_clock::now();
    list.sort();
    auto list_endS = high_resolution_clock::now();
    auto list_durationS = duration_cast<microseconds>(list_endS - list_startS);

    auto list_startI = high_resolution_clock::now();
    auto it = list.begin();
    advance(it, (list.size()/2));
    list.insert(it, test);
    auto list_endI = high_resolution_clock::now();
    auto list_durationI = duration_cast<microseconds>(list_endI - list_startI);

    auto list_startD = high_resolution_clock::now();
    it = list.begin();
    advance(it, (list.size()/2)-1);
    list.erase(it);
    auto list_endD = high_resolution_clock::now();
    auto list_durationD = duration_cast<microseconds>(list_endD - list_startD);

    // This code moves the pointer inside inputFile back to the beginning of the file so we can read it again.
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    // SET 

    auto set_startR = high_resolution_clock::now();
    while(getline(inputFile, code)){
        set.insert(code);
    }
    auto set_endR = high_resolution_clock::now();
    auto set_durationR = duration_cast<microseconds>(set_endR - set_startR);

    auto set_startI = high_resolution_clock::now();
    set.insert(test);
    auto set_endI = high_resolution_clock::now();
    auto set_durationI = duration_cast<microseconds>(set_endI - set_startI);

    auto set_startD = high_resolution_clock::now();
    auto i = set.begin();
    advance(i, (set.size()/2)-1);
    set.erase(i);
    auto set_endD = high_resolution_clock::now();
    auto set_durationD = duration_cast<microseconds>(set_endD - set_startD);

    cout << right << setw(30) << "*** OUTPUT TABLE ***"<< endl;
    cout << right << setw(10) << "Operation" << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    cout << right << setw(10) << "Read" << setw(10) << vector_durationR.count() << setw(10) << list_durationR.count() << setw(10) << set_durationR.count() << endl;
    cout << right << setw(10) << "Sort" << setw(10) << vector_durationS.count() << setw(10) << list_durationS.count() << setw(10) << "-1" << endl;
    cout << right << setw(10) << "Insert" << setw(10) << vector_durationI.count() << setw(10) << list_durationI.count() << setw(10) << set_durationI.count() << endl;
    cout << right << setw(10) << "Delete" << setw(10) << vector_durationD.count() << setw(10) << list_durationD.count() << setw(10) << set_durationD.count() << endl;

    return 0;
}
