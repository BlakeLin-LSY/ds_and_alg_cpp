#include <iostream>
#include <string>
using namespace std;

string LRUCache(string strArr[], int arrLength){

    return strArr[0];
}

int main(void){
    
    string A[] = {"A", "B", "A", "C", "A", "B"};
    int arrLength = sizeof(A) / sizeof(*A);
    cout << LRUCache(A, arrLength);
    return 0;
}