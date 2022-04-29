#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main(){

    return 0;
}



/*
Container "string"      -> same as vector;

Operations          |   Big-Oh efficiency
---
index[]             |   O(1)
index assignment =  |   O(1)
push_back()         |   O(1) -> typically (except size exceeded)
pop_back()          |   O(1)
erase(i)            |   O(n)
insert(i,item)      |   O(n)
find(str, stp, item)|   O(n)    or O(log n)  -> depends on "sorted or not"
reserve()           |   O(n)    **
begin()             |   O(1)
end()               |   O(1)
size()              |   O(1)


*/