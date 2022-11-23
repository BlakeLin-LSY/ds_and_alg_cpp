/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k=primes.size();
        vector<long> v(n+1, 1);
        vector<long> pPrime_i(k+1, 1);
        vector<long> vPrime_i(k+1, 1);
        // for(int i=1; i<=k; ++i) vPrime_i[i]=primes[i-1];

        int count=1;
        while(count<=n){
            long cur=INT_MAX;
            for(int i=1; i<=k; ++i) cur=min(cur, vPrime_i[i]);
            v[count++]=cur;
            for(int i=1; i<=k; ++i) {
                if(cur==vPrime_i[i]){
                    vPrime_i[i]=primes[i-1]*v[pPrime_i[i]];
                    ++pPrime_i[i];
                }
            }
        }
        return v[n];
    }
};
/*
# Idea:

    1. prime in primes as each list, merge them together

    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. Primes length can be large.
      2. Comparing primes can use Priority Queue to reduce the complexity.
      (N*k) --> (N*logk)  since insertion of min heap is logk.
      3. large number overflow potential -> change int to long

# Note:
    Similar problem 264. Ugly number II

87/87 cases passed (236 ms)
Your runtime beats 93.19 % of cpp submissions
Your memory usage beats 75.09 % of cpp submissions (10.3 MB)

TC: O(N*k)  --> k == primes.size()
SC: O(N*k)
*/
// @lc code=end

