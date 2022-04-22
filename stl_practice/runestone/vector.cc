#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void test_f(int num){
    vector<int> v;
    // v.reserve(num);      // reserve gives faster push_back (no extra need to expand vector size)
    for (int i = 0; i < num; ++i){
        v.push_back(i);
    }
}

int main(){
    clock_t t_begin, t_end;
    double t_secs;
    int num_runs = 10000;
    t_begin = clock();
    for (int i = 0; i < num_runs; ++i){
        test_f(i);
    }
    t_end = clock();
    t_secs = double(t_end - t_begin)/CLOCKS_PER_SEC;
    cout << fixed << endl;
    cout << "push_back " << t_secs << " ms" << endl;

    return 0;
}


/*
Container "vector"

Operations          |   Big-Oh efficiency
---
index[]             |   O(1)
index assignment =  |   O(1)
push_back()         |   O(1)
pop_back()          |   O(1)
erase(i)            |   O(n)
insert(i,item)      |   O(n)
find(str, stp, item)|   O(n)    or O(log n)  -> depends on "sorted or not"
reserve()           |   O(n)    **
begin()             |   O(1)
end()               |   O(1)
size()              |   O(1)


*/