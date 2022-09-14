#include<iostream>
#include<string>
using namespace std;

/*
Using string to solve
*/

void solve(int t){
    string s;
    cin >> s;
    long long sum = 0;
    for(char c:s){
        sum += (c - '0');
    }
    sum %= 9; // --> Insert value to the new number;
    sum = (9-sum) % 9;
    int pos = 0; // from left to right of the string;
    for (char c:s){
        if ((c-'0') > sum) break;
        ++pos;
    }
    if (sum == 0) pos++; 
    s.insert(pos, to_string(sum));

    cout << "Case #" << t << ": " << s << endl;

}

int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; ++i){
        solve(i+1);
    }
    return 0;
}