#include <iostream>
#include <string>
using namespace std;

string ArrayMatching(string strArr[], int arrLength){

    return strArr[0];
}

int main(void){

    // string A[] = coderbyteInternalStdinFunction(stdin);
    string A[] = {"[5, 2, 3]", "[2, 2, 3, 10, 6]"};
    int arrLength = sizeof(A) / sizeof(*A);
    cout << ArrayMatching(A, arrLength);
    return 0;
}