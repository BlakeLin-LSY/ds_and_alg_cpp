#include<iostream>
using namespace std;

int fn(int n){
    if (n == 1 or n == 2) return 1;
    return fn(n-1) + fn(n-2);
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5,
                10, 11, 13, 14, 15};
    for(auto x: a){
        cout << "fn(" << x << ")= " << fn(x) << endl;
    }


    return 0;
}