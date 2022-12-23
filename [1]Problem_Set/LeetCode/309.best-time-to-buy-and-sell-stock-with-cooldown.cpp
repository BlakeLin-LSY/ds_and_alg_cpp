/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for(int i=0; i<n; ++i){
            if(i==0){
                // base case 1
                dp[i][0]=0;
                dp[i][1]=-prices[i];
            }else if(i==1){
                // base case 2
                dp[i][0]=max(dp[i-1][0], dp[i-1][1]+prices[i]);
                dp[i][1]=max(dp[i-1][1], 0-prices[i]);
            }else{
                dp[i][0]=max(dp[i-1][0], dp[i-1][1]+prices[i]);
                dp[i][1]=max(dp[i-1][1], dp[i-2][0]-prices[i]);
            }
        }
        // dp[n-1][0] is the maximum, since prices are positive
        return dp[n-1][0];
    }
};
/*
:
    Buy, sell stock series problem -> with cooldown
    dp problem, greedy

# Idea:
    ## 1st
        dp[i][0] --> buy
        dp[i][1] --> sell

        dp[i][0]=max(dp[i-1][0], dp[i-1][1]+prices[i])
        dp[i][1]=max(dp[i-1][1], dp[i-2][0]-prices[i])
      
    ### Key Points:
      1. Cool down -> check dp[i-2][0] for the dp[i][1]
      2. Base case for the dp

    ### Any Improvement Ideas / Related Questions:
      - 

# Note:

210/210 cases passed (16 ms)
Your runtime beats 19.12 % of cpp submissions
Your memory usage beats 46.95 % of cpp submissions (11.9 MB)

TC: O(N)
SC: O(N)

========================================
2022-Dec Day-23, Leetcode November Challenge Study Room Event
*/
// @lc code=end

