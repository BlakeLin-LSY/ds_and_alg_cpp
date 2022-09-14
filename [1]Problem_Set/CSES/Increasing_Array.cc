#include<iostream>

using namespace std;

int main(){
    long long n;
    long long ans = 0, l = 0, r = 0;
    cin >> n;
    cin >> l;
    for(int i=1; i < n; ++i){
        cin >> r;
        if (l > r){
            ans += (l-r);
        }
        else{
            l = r;
        }
    }
    cout << ans;    // Note the overflow of int value
}