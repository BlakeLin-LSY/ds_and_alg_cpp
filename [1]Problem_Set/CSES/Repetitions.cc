#include<iostream>
#include<string>

using namespace std;

// int main(){
//     string s;
//     char c;
//     int max_count = 0;
//     int count = 1;
    
//     cin >> s;

//     c = s[0];
//     for(int i = 1; i <s.size(); ++i){
//         // cout << i << "," << s[i] << endl;
//         if (s[i] == c) count++;
//         else{
//             c = s[i];
//             if (count > max_count) max_count = count;
//             count = 1;
//         }
//     }
//     if (count > max_count) max_count = count;
//     cout << max_count;
//     return 0;
// }

int main(){

    string s;
    char c = 'A';
    int ans = 1, count = 0;
    cin>>s;
    for(auto w:s){
        if(w == c){
            ++count;
            ans = max(ans, count);
        }
        else{
            c = w;
            count = 1;
        }
    }
    cout << ans;
}