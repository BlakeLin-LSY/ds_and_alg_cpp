#include <iostream>
#include <ctime>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    int n = 10000;
    vector<int> v;
    unordered_map<int, int> map;
    for (int a = n; a < 100*n; a+=20000){
        // Vector
        clock_t t_begin = clock();
        // vector<int> v;
        for (int i = 0; i < a; ++i){
            v.push_back(i);
        }
        clock_t t_end = clock();
        double t_1 = double(t_end - t_begin)/CLOCKS_PER_SEC;


        // Hash table
        clock_t t_begin2 = clock();
        // unordered_map<int, int> map;
        for (int j = 0; j < a; ++j){
            map[j] = NULL;
        }

        clock_t t_end2 = clock();
        double t_2 = double(t_end2 - t_begin2)/CLOCKS_PER_SEC;

        cout << fixed << endl;
        cout << a << "\t" << t_1 << "\t" << t_2 << endl;
    }

    return 0;
}

// Check this web --> "unordered_map" slower than "vector", even they are O(1)
// https://stackoverflow.com/questions/55451825/why-is-vector-faster-than-unordered-map


/*
Container "map" <-> hash table
<unordered_map>

"""
    Match "keys" to their "values" using "hash function"
"""

Operations          |   Big-Oh efficiency
---
find                |   O(1)
insert              |   O(1)
erase               |   O(1)
contains            |   O(1)     **
iteration           |   O(n)


*/