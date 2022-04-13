#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

/*
WA --> for large n --> 10**123456 --> exceeded long long range, need to using "String" to solve;

long long ~ 10**(18) --> comes from (2**64 -1) == (2**10)**6 * 2**4 -1 == 1024**6 ** 16 -1 ~= 10**18 * 16 - 1;
short == (2 bytes) == 2**16 -1 == 64 * 1024 - 1 == 65535
int (4 bytes) == -65535 ~ 655356
*/

void solve(int t){
    long long n;
    long long res;
    cin >> n;
    vector<int> v;
    int sum=0, val=0, n_10=1;   // extra 1 digit added;
    res=0;
    while(n > 0){
        val = n%10;
        v.push_back(val);
        sum += val;
        n /= 10;
        ++n_10;
    }
    int add_v = (9-(sum%9)) % 9;
    int current_v = 0;
    while(!v.empty()){
        current_v = v.back();
        v.pop_back();
        if (add_v < current_v && (add_v > 0 || res != 0)){
            res += pow(10,n_10-1)*add_v;
            add_v = 10;
            --n_10;
        }
        res += pow(10,n_10-1)*current_v;
        --n_10;
    }
    if (n_10 != 0) res += add_v;    // Insert at last digit;
    cout << "Case #" << t << ": " << res << endl;

}



int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; ++i){
        solve(i+1);
    }
    return 0;
}



/*

Input:
    N -> positve, no leading 0
Goal:
    insert "1" digit number(0~9) to make N' % 9 == 0, and smallest N'


Idea:

    Math:
        Sum of every digits of number N%3==0 -> sum_N % 3 == 0
        %9 == 0 -> must be %3 == 0

    Requirements:
        1. %9 == 0  --> (find sum of every number in N)
        2. smallest --> (start insert number from the right)

Tests:

1. [5]
--> insert 4 >> 45 (45%9 == 0)
--> insert 4 >> 54 (54%9 == 0) -> but 54 > 45

2. [33]
3+3 = 6

9 - (6%9) = 3 -> add value 3 from the right --> 333 ( 333 % 9 == 0)


3. [12121]
1+2+1+2+1 = 7
9 - (7%9) = 2 -> add 2 from the right --> 121212 (121212%9 == 0)


//Extra test cases (edge cases)
sum_N > 9:
    [987]
    9+8+7 = 25 (%9 = 2)
    9872
    9827
    9287
    2987 ** --> smallest one

--> added extra value not always from the right (if original N value leading value is larger)

:
    Add extra value, compare to each digit number of N, insert at
        left: if new_v < leading
        right: if new_v > leading

*/