/*
 * @lc app=leetcode id=1201 lang=cpp
 *
 * [1201] Ugly Number III
 */

// @lc code=start
class Solution {
public:
    // // O(N) solution
    // int nthUglyNumber(int n, int a, int b, int c) {
    //     int k=1;
    //     long vA=a, vB=b, vC=c;
    //     long cur=0;
    //     while(k<=n){
    //         cur=min(min(vA, vB), vC);
    //         ++k;
    //         if(cur==vA) vA+=a;
    //         if(cur==vB) vB+=b;
    //         if(cur==vC) vC+=c;
    //     }
    //     return cur;
    // }

    // TC: O(logN)
    int nthUglyNumber(int n, int a, int b, int c) {
        long l=1, r=(long)2e9;
        while(l<=r){
            long m=l+(r-l)/2;
            long res=f(m, a, b, c);
            if(res<n) l=m+1;
            else r=m-1;
        }
        return l;
    }

    // return numbers can be divided in the range [1...num]
    long f(int num, int a, int b, int c){
        long setA=num/a;
        long setB=num/b;
        long setC=num/c;
        long setAB=num/lcm(a, b);
        long setAC=num/lcm(a, c);
        long setBC=num/lcm(b, c);
        long setABC=num/lcm(lcm(a, b), c);
        long k=setA+setB+setC-setAB-setAC-setBC+setABC;
        return k;
    }

    long gcd(long a, long b) {
        if (a < b) {
            return gcd(b, a);
        }
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
};
/*
# Idea:

    1. a-dividalbe ugly numbers
    2. b-dividalbe ugly numbers
    3. c-dividalbe ugly numbers


# Note:
    Similar to 264. Ugly number II

    ! Memory limit !
    - No need to store in array.
    - Large number range --> use "long"

    # Key:
    1. value 1 is not in the divisible ugly number...
    2. divisible not have to be only ugly number divisible...

TC: O(N) -> TLE in this problem
SC: O(N)


    Further optimize:
    A + B + C - A ∩ B - A ∩ C - B ∩ C + A ∩ B ∩ C
        A ∩ B:  n / (lcm(a, b))
        A ∩ C:  n / (lcm(a, c))
        B ∩ C:  n / (lcm(b, c))
        A ∩ B ∩ C:  n / lcm(lcm(a, b), c)

53/53 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 30.29 % of cpp submissions (6 MB)

TC: O(logN)
SC: O(1)
*/
// @lc code=end

