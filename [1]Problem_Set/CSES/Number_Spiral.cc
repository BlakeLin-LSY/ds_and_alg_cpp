#include <iostream>

using namespace std;

int main(){
    long long t;
    cin >> t;
    long long x, y;
    long long z, ans;
    while(t--){
        cin >> y >> x;
        z = max(x, y);
        ans = z*z;
        if (x == y){
            ans -= (z-1);
        }
        else if (z == x){
            if (z%2) ans -= (y-1);
            else ans -= (z-1)+(z-y);
        }else if (z == y){
            if (z%2) ans -= ((z-1)+(z-x));
            else ans -= (x-1);
        }
        cout << ans << endl;
    }
    return 0;
}


/*

idea:
Check x, y is even or odd
- From column (4, 16, 36...) -> 2n^2
- From row    (9, 25, 49...) -> (2n+1)^2
max(y,x) --> find upper bound of the value z**2, where z = max(y, x);

if z == x == y --> z**2 - (z-1)

if z == x:
    even:
        z**2 - (z - 1) - (z-y)
    odd:
        z**2 - (y-1)

if z == y:
    even:
        z**2 - (x-1)
    odd:
        z**2 - (z - 1) - (z-x)

*/