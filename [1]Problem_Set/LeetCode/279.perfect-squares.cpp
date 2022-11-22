/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        int k=1;
        while((k*k) <= n){
            int sq=k*k;
            if(sq==n) return 1;
            for(int i=sq; i<n+1; ++i){
                dp[i]=min(dp[i-sq]+1, dp[i]);
            }
            ++k;
        }
        return dp[n];
    }
};
/*
:
    Find minimum number (square sum) is equal to n
    return number of square values (e.g. 16 = 4^2 ==> return 1)

# Idea:
    ## 1st
        Find closest k ==> k^2 <= n
    1. n / k1^2 = c1
    2. n-(c1*k1^2)  > 0 -> continue to find next k
                    ==0 -> return sum(ci)

    ### Edge Case:
      1. n==1   -> return 1
      2. 1*(3^2) + 3*(1^2) > 3*(2^2)

    ### Key Points:
      1. Return value
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

00:02:  Read problem
00:08:  first implement
00:23:  debuging
00:27:  Failed, case 564/588 --> unable to solve using current algo

# Note:

    Edge case 564/588:
        48      >>  3
        1*(5^2) + 2*(3^2)

    Reference:
    https://leetcode.com/problems/perfect-squares/solutions/1520447

588/588 cases passed (244 ms)
Your runtime beats 68.54 % of cpp submissions
Your memory usage beats 51.59 % of cpp submissions (9.1 MB)

TC: O(N*sqrt(N))
SC: O(N)

========================================
Day-22, Leetcode November Challenge Study Room Event
*/
// @lc code=end

