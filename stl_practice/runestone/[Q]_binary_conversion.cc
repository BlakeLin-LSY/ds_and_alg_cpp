#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


string toBinary(int val){
    string res = "";
    stack<string> stack_str;
    int tmp = 0;

    while (val > 0){
        tmp = val % 2;
        stack_str.push(to_string(tmp));
        val /= 2;
    }   // val is "passed by value" --> that is why "in-place" modification no worry;

    while (!stack_str.empty()){
        res += stack_str.top();
        stack_str.pop();
    }

    return res;
}


int main(){
    vector<int> v = {17, 45, 96};
    for (int i = 0; i < v.size(); ++i){
        cout << "Input = " << v[i] << "\t Binary value = "
        << toBinary(v[i]) << endl;
    }

    for (int i = 0; i < v.size(); ++i){
        cout << "[after]Input = " << v[i] << endl;
    }

    return 0;
}