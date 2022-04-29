#include <iostream>
#include <ctime>

using namespace std;

void foo(int n){
    clock_t begin = clock();
    int theSum = 0;
    for (int i = 0; i < n; ++i){
        theSum+=i;
    }
    clock_t end = clock();
    double elapsed_s = double(end - begin) / CLOCKS_PER_SEC;
    cout << fixed << endl;      // Important for fixed output format;
    cout << "Sum is " << theSum << " required " << elapsed_s << endl;
};

int main(){

    for (int i = 0; i < 6; ++i){
        foo(1000000);
    }
    return 0;
}