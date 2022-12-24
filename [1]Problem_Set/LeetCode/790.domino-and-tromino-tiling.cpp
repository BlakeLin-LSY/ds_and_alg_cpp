/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
public:
    int numTilings(int n) {
        vector<long long> dp(n+1, 1);
        // dp[0]=1;
        // dp[1]=1;
        int MOD=1e9+7;
        for(int width=1; width<=n; ++width){
            long long totalWays=0;
            for(int fixWidth=1; fixWidth<=width; ++fixWidth){
                int leftWidth=width-fixWidth;
                long long ways=dp[leftWidth];
                // because from fixWidth > 2, two configurations exist for each case
                // fixWidthConfiguration appended to all dp[leftWidth] configurations
                if(fixWidth>2) ways=(ways*2)%MOD;
                totalWays=(totalWays+ways)%MOD;
            }
            dp[width]=totalWays;
        }
        return dp[n];
    }
};
/*
:
    2*n in total tile numbers, 
    tile shape 1: 2
    tile shape 2: 3

    return the total number of combination to build up for 2*n shape

# Idea:
    ## 1st
        Go through it
    
    shape 1:    | or --
    shape 2:    |- or |_

    n=1 -> 1
    n=2 -> 1+1 = 2 (|| , =)
    n=3 -> dp[1]+dp[2], dp[2]+dp[1], dp[1]+dp[1]+dp[1], 2 == |- and |_
    n=4 -> dp[1]+dp[3], dp[3]+dp[1], dp[2]+dp[2], dp[1]+dp[1]+dp[1]+dp[1]
    n=5 -> possibles to build 5 -> (1,4), (2,3), (3, 2), (4, 1)

    dp[1]=1
    dp[2]=2
    dp[3]=dp[1]*dp[2]+dp[1]+2=5
    dp[4]=dp[1]*dp[3]+dp[2]*dp[2]+1=10


    ### Key Points:
      1. +1 or +2 -> like climbing stairs, but in 2d

00:28:  Not complete the pattern

# Note:

Reference

39/39 cases passed (30 ms)
Your runtime beats 7.33 % of cpp submissions
Your memory usage beats 51.09 % of cpp submissions (6.4 MB)
https://leetcode.com/problems/domino-and-tromino-tiling/solutions/2944191/complete-explanation-with-images-easy-to-understand/

TC: O(N)
SC: O(N)

========================================
2022-Dec Day-24, Leetcode November Challenge Study Room Event
*/
// @lc code=end

