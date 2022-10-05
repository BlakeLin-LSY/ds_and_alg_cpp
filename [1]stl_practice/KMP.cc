// To check auto type
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> build(string &t) {
    vector<int> F(t.size());
    F[0] = -1;
     
    for (int i = 1, pos = -1 ; i < t.size() ; i++) {
        while (~pos && t[i] != t[pos+1])
            pos = F[pos];
 
        if (t[i] == t[pos+1])
            pos++;
 
        F[i] = pos;
    }
    return F;
}

void lps_func(string txt, vector<int>&Lps){
    Lps[0] = 0;                   
    int len = 0;
    int i=1;
    while (i<txt.length()){
        if(txt[i]==txt[len]){   
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else{                   
            if(len==0){         
                Lps[i] = 0;
                i++;
                continue;
            }
            else{              
                len = Lps[len-1];
                continue;
            }
        }
    }
}

vector<int> my_lps(string& s){
    int n=s.length();
    vector<int> ret(n);
    for(int i=1, pos=0; i<n; ++i){
      if(s[i] == s[pos]){
        ++pos;
        ret[i]=pos;
      }else if(pos>0){
        pos=ret[pos-1];
        --i;
      }else ret[i]=0;
    }
    return ret;
}

int main(){
    // string s="abbcatddg";
    // string s="abcabcabcabe";
    // string s="ABABABCABABABCABABABC";
    string s="aabaaac";
    string t1="abca";
    string t2="bca";

    for(auto x:s){
      cout << x << " ";
    }
    cout << endl;

    vector<int> lps(s.length());
    lps_func(s, lps);

    for(auto x:lps){
      cout << x << " ";
    }
    cout << endl;

    auto s_ = build(s);
    for(auto x:s_){
      cout << x << " ";
    }
    cout << endl;

    auto ss = my_lps(s);
    for(auto x:ss){
      cout << x << " ";
    }
    cout << endl;

    return 0;
}