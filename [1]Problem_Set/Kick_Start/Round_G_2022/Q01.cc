#include <bits/stdc++.h>
using namespace std;

int solve(int M, int N, int P, const vector<vector<int>>& arr) {
    int curP, curMax, res=0;
    int diff;
    for(int i=0; i<N; ++i){
        curMax=0;
        for(int j=0; j<M; ++j){
            if(j==P-1) continue;
            curMax=max(curMax, arr[j][i]);
        }
        curP=arr[P-1][i];
        if(curP < curMax) diff=curMax-curP;
        else diff=0;
        res+=diff;
    }
    return res;
}

int main() {
    
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int M, N, P;
        cin >> M >> N >> P;
        vector<int> participant(N, 0);
        vector<vector<int>> v(M, participant);
        // int tmp;
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                // cin >> tmp;
                cin >> v[i][j];
            }   
        }
        cout << "Case #" << tc << ": " << solve(M, N, P, v) << endl;
    }
    return 0;
}


/*
:
    Find difference, and sum up
    
    N days,
    M participants

TC:
SC:
*/