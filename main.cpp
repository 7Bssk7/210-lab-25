#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
#include <list>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

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


    // LIST

    auto list_startR = high_resolution_clock::now();
    while(getline(inputFile,code)){
        list.push_back(code);
    }
    auto list_endR = high_resolution_clock::now();
    auto list_durationR = duration_cast<microseconds>(list_endR - list_startR);

    cout << "List read: " << list_durationR.count() << " microseconds" << endl;

    auto list_startS = high_resolution_clock::now();
    list.sort();
    auto list_endS = high_resolution_clock::now();
    auto list_durationS = duration_cast<microseconds>(list_endS - list_startS);
    cout << "List sort: " << list_durationS.count() << " microseconds" << endl;

    // This code moves the pointer inside inputFile back to the beginning of the file so we can read it again.
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    auto list_startI = high_resolution_clock::now();
    auto it = list.begin();
    advance(it, (list.size()/2));
    list.insert(it, "TESTCODE");
    auto list_endI = high_resolution_clock::now();
    auto list_durationI = duration_cast<microseconds>(list_endI - list_startI);
    cout << "List insert: " << list_durationI.count() << " microseconds" << endl;

    auto list_startD = high_resolution_clock::now();
    it = list.begin();
    advance(it, (list.size()/2)-1);
    list.erase(it);
    auto list_endD = high_resolution_clock::now();
    auto list_durationD = duration_cast<microseconds>(list_endD - list_startD);
    cout << "List delete: " << list_durationD.count() << " microseconds" << endl;


    // SET 

    auto set_startR = high_resolution_clock::now();
    while(getline(inputFile, code)){
        set.insert(code);
    }
    auto set_endR = high_resolution_clock::now();
    auto set_durationR = duration_cast<microseconds>(set_endR - set_startR);

    cout << "Set read: " << set_durationR.count() << " microseconds" << endl;

    cout << "Set sort: -1 microseconds" << endl;

    auto set_startI = high_resolution_clock::now();
    set.insert("TESTCODE");
    auto set_endI = high_resolution_clock::now();
    auto set_durationI = duration_cast<microseconds>(set_endI - set_startI);
    cout << "Set insert: " << set_durationI.count() << " microseconds" << endl;

    auto set_startD = high_resolution_clock::now();
    auto i = set.begin();
    advance(i, (set.size()/2)-1);
    set.erase(i);
    auto set_endD = high_resolution_clock::now();
    auto set_durationD = duration_cast<microseconds>(set_endD - set_startD);
    cout << "Set delete: " << set_durationD.count() << " microseconds" << endl;

    inputFile.clear();
    inputFile.seekg(0, ios::beg);


    //VECTOR

    auto vector_startR = high_resolution_clock::now();
    while(getline(inputFile, code)){
        vector.push_back(code);
    }
    auto vector_endR = high_resolution_clock::now();
    auto vector_duration = duration_cast<microseconds>(vector_endR - vector_startR);

    cout << "Vector read: " << vector_duration.count() << " microseconds" << endl;

    auto vector_startS = high_resolution_clock::now();
    sort(vector.begin(), vector.end());
    auto vector_endS = high_resolution_clock::now();
    auto vector_durationS = duration_cast<microseconds>(vector_endS - vector_startS);
    cout << "Vector sort: " << vector_durationS.count() << " microseconds" << endl;

    auto vector_startI = high_resolution_clock::now();
    vector.insert(vector.begin() + (vector.size()/2),"TESTCODE");
    auto vector_endI = high_resolution_clock::now();
    auto vector_durationI = duration_cast<microseconds>(vector_endI - vector_startI);
    cout << "Vector insert: " << vector_durationI.count() << " microseconds" << endl;



    auto vector_startD = high_resolution_clock::now();
    vector.erase(vector.begin() + ((vector.size()/2)-1));
    auto vector_endD = high_resolution_clock::now();
    auto vector_durationD = duration_cast<microseconds>(vector_endD - vector_startD);
    cout << "Vector delete: " << vector_durationD.count() << " microseconds" << endl;


    
    


    
    

    
    

    return 0;
}
