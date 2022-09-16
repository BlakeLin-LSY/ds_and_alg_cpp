// Template for cpp STL library practices
#include<iostream>
using namespace std;


template<typename T>
constexpr T pi = T(3.1415926535897932385L); //constant expression

template<typename T>
T area_of_circle(const T& r){
    return r*r*pi<T>;
}

int main(){

    cout.precision(20);
    cout << pi<long double> << endl;

    cout << "===========" << endl;
    cout.precision(30);
    cout << pi<long double> << endl;

    cout << "===========" << endl;
    cout.precision(10);
    cout << pi<float> << endl;

    cout << "===========" << endl;
    cout.precision(20);
    cout << pi<float> << endl;          // Overflow


    cout << endl << "===area===" << endl;
    cout.precision(20);
    cout << "long double: " << area_of_circle<long double>(3) << endl;

    cout.precision(20);
    cout << "float: " << area_of_circle<float>(3) << endl;

    return 0;
}



/*
=== Used Library ===
stl - template


Summary:
    Using template to create variable/function with input type.

Methods:
    template<typename T>
    ...

*/