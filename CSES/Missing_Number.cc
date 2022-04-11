#include<iostream>

using namespace std;

int main(){
    long long n, s = 0;
    int tmp = 0;
    cin >> n;
    for(int i=1; i<n; ++i){
        cin >> tmp;
        s+=tmp;
    }
    cout << ((n+1)*n/2) - s << endl;
    return 0;
}