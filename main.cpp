#include <iostream>
#include <fstream>
#include <set>
#include <list>
#include <vector>
#include <chrono>
using namespace std;

int main() {
    ifstream inputFile("codes.txt");
    string code;
    list<string> list;
    set<string> set;
    vector<string> vector;
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/