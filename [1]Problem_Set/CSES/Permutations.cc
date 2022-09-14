#include <iostream>

using namespace std;


int main(){
    long long n;
    cin>>n;
    if (n==1) cout << '1';
    else if (n==2 || n==3) cout << "NO SOLUTION";
    else{
        for (int i=2; i<=n; i+=2){
            cout << i << " ";
        }
        for (int i=1; i<=n; i+=2){
            cout << i << " ";
        }
    }
    return 0;
}



// // idea 2
// int main(){
//     long long n;
//     cin>>n;
//     long long mid = n/2 + 1;
//     if ((mid - 2 < 1) || (mid + 2 > n))
//         cout << "NO SOLUTION" << endl;
//     else{
//         cout << mid << " ";
//         while ((mid + 1) <= n){
//             cout << (mid - 2) << " ";
//             cout << (mid + 1) << " ";
//             ++mid;
//         }
//     }
//     return 0;
// }


/*
input: 1 ~ n
- Adjacent difference > 1


1st idea:
- Start from the end and beginning to assign to the array
(which have largest difference)
--> when meet the "mid", this could lead to the issue.

-> cross out

2nd idea:
- Find minimum difference > 1 pairs ( x-2 | x | x+2 )
- Start from the mid value -> (n/2)


--> Final idea:
4:
2 4 1 3 --> even value (with gap 2) + odd value (with gap 2)
*/