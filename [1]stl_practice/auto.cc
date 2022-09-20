// To check auto type
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main(){
    int i = 47;
    const char* cstr = "this is a c-string";
    const string sclass = string("this is a string class string");

    auto x = "this is a c-string";
    decltype(x) y;

    return 0;
}