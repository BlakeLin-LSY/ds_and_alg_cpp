/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool> isPrime(n, true);
        for(int i=2; i*i<n; ++i){
            if(isPrime[i]){
                for(int j=2; i*j<n; ++j) isPrime[i*j]=false;
            }
        }
        for(int i=2; i<n; ++i) if(isPrime[i]) ++count;

        return count;
    }
};


/*
:
    Count prime numbers

# Idea:
    first idea is to check prime numbers, and ++i to check i<n;
    >> which lead to TLE (since check one by one, withe "while-loop" + "for-loop")
    TC:O(N^2)

    Final:
        1. Exclude the impossibles one by one (2...i*i < n)
        >> Sieve

    DP-solution
    https://leetcode.com/problems/count-primes/solutions/459400/c-solution-with-dp/


TC:O(N*log(log(N)))
SC:O(N)
*/
// @lc code=end

