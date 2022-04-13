#include <iostream>
#include <string>

using namespace std;

int main(){
    long long n;
    cin >> n;
    int t = 1;
    while (n--){
        string I, P;
        cin >> I >> P;
        int res = P.size() - I.size();
        cout << "Case #" << t << ": ";
        ++t;
        if (res < 0){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        int j = 0;
        for (int i=0; i<I.size(); ++i){
            while ((I[i] != P[j]) && j < P.size()){
                ++j;
            }
            if (j == P.size()){
                res = -1;
                break;  // Early break for Impossible
            }
            ++j;
        }
        cout << (res == -1 ?"IMPOSSIBLE":to_string(res)) << endl;
    }
    return 0;
}


/*
I: Input (Corrected Answer)
P: To check string (only remove letters to make I == P)


1. Check two string length (I & P)
--> if ( P < I ) -> IMPOSSIBLE

2. check letters one by one (iterate through I)
--> if I[i] != P[j] --> record j, and make j++, until I[i_] == P[j_]

3. If meet I[i_] == P[j_] condition -> means I and P can be the same string by 
removing letters from P.

3.1 Check if meet the P's end -> output recorded js and ' extra j' ' then print out
3.2 IMPOSSIBLE conditions

*/