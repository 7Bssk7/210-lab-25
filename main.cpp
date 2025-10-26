#include <iostream>
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

    auto start = high_resolution_clock::now();
    while(getline(inputFile,code)){
        list.push_back(code);
    }
    auto end = high_resolution_clock::now();

    auto list_duration = duration_cast<microseconds>(end - start);
    cout << "List read: " << list_duration.count() << " microseconds" << endl;

    // This code moves the pointer inside inputFile back to the beginning of the file so we can read it again.
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    start = high_resolution_clock::now();
    while(getline(inputFile, code)){
        set.insert(code);
    }
    end = high_resolution_clock::now();

    auto set_duration= duration_cast<microseconds>(end - start);
    cout << "Set read: " << set_duration.count() << " microseconds" << endl;

    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    start = high_resolution_clock::now();
    while(getline(inputFile, code)){
        vector.push_back(code);
    }
    end = high_resolution_clock::now();

    auto vector_duration = duration_cast<microseconds>(end - start);

    cout << "Vector read: " << vector_duration.count() << " microseconds" << endl;
    

    
    

    return 0;
}
