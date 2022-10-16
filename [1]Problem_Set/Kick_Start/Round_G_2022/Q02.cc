#include <bits/stdc++.h>
using namespace std;

void solve() {
    int R_s, R_h, N_r, N_y;
    cin >> R_s >> R_h;
    cin >> N_r;
    int x, y, d;
    int D=(R_s+R_h)*(R_s+R_h);
    vector<int> v_r;
    for(int i=0; i<N_r; ++i){
        cin >> x >> y;
        d = x*x + y*y;
        if(D >= d) v_r.push_back(d);
    }

    vector<int> v_y;
    cin >> N_y;
    for(int i=0; i<N_y; ++i){
        cin >> x >> y;
        d = x*x + y*y;
        if(D >= d) v_y.push_back(d);
    }
    sort(v_r.begin(), v_r.end());
    sort(v_y.begin(), v_y.end());
    
    int count;
    if(v_r.size() == 0) {
        cout << "0 " << v_y.size();
        return;
    }
    if(v_y.size() == 0) {
        cout << v_r.size() << " 0";
        return;
    }
    
    count=0;
    int i=0;
    if(v_r[0] >= v_y[0]){
        while(v_r[i]<v_y[0]){
            ++count, ++i;
        }
        cout << count << " 0";
    }
    else {
        while(v_y[i]<v_r[0]){
            ++count, ++i;
        }
        cout << "0 " << count;
    }
}

int main() {
    
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": "; 
        solve();
        cout << endl;
    }
    return 0;
}



/*
:
    Calculate distance, comparing to (0,0)

Edge case:
    - Test Case #2 : Not always 1:1 countered --> compare distance
*/