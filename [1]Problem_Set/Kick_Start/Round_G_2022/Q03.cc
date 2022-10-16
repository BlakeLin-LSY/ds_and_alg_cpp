#include <bits/stdc++.h>
using namespace std;

int solve() {
    int ans=0;
    int dp0=0, dp1=0;
    int N;
    cin >> N;
    int tmp;
    for(int i=0; i<N; ++i){
        cin >> tmp;
        if(dp0>0){
            dp0=dp0+tmp;
        }else dp0=0;
        dp1=0+tmp;

        if(dp1<=0) dp1=0;

        ans+= dp0 + dp1;
        dp0=dp1;
    }
    return ans;
}

int main() {
    
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": " << solve() << endl;
    }
    return 0;
}



/*
:
    DP --> two state sum 
    dp[0] --> prev_sum
    dp[1] --> 0 + current

*/