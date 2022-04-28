#include <iostream>
#include <deque>
#include <string>
#include <algorithm>    // provides "erase()"

using namespace std;

string strPreProcess(string s){
    string s_res = "";
    for (int i = 0; i < s.length(); ++i){
        s_res += tolower(s[i]);
    }

    string remove_chrs = "";
    for (int ascii_val = 32; ascii_val < 65; ++ascii_val){
        // cout << (char)ascii_val << " ";
        remove_chrs += (char)ascii_val;
    }
    for (int i = 0; i < remove_chrs.length(); ++i){
        s_res.erase(remove(s_res.begin(), s_res.end(), remove_chrs[i]), s_res.end());
    }

    return s_res;
}

bool palChecker(string s){
    deque<char> dq_char;
    int n = s.length();
    // T(n) = O(n)
    for (int i = 0; i < n; ++i){
        dq_char.push_back(s[i]);
    }

    bool stillEqual = true;

    // T(n) = O(n)  --> worst;  O(1) --> best;
    char front, rear;
    while(dq_char.size() > 1 && stillEqual){
        front = dq_char.front();
        rear = dq_char.back();

        if (front != rear){
            stillEqual = false;
            break;
        }
        dq_char.pop_front();
        dq_char.pop_back();
    }
    return stillEqual;
}


int main(){
    string s_in;
    int n = 3;
    for (int i = 0; i < n; ++i){
        cout << "Enter arbitrary string to check if it is Palindrome:\n";
        // cin >> s_in;
        getline(cin, s_in);
        cout << "Preprocessed String input:\n" << strPreProcess(s_in) << endl;
        cout << palChecker(strPreProcess(s_in)) << endl;
    }
    return 0;
}

/*
    Palindrome:
        xxaxx
        abccba

    
    Easily solved (and check if string a palindrome) by "deque"

    Check "rear" and "front" character
*/