/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        int n=nums.size();
        memo.resize(n, -1);
        return dp(nums, 0);
    }

    int dp(vector<int>& nums, int start){
        if(start>=memo.size()){
            return 0;
        }

        if(memo[start]!=-1) return memo[start];

        int res=max(dp(nums, start+1), nums[start]+dp(nums, start+2));
        memo[start]=res;
        return res;
    }
};
/*
:
    Classic house robber (dp), neighbor connected

# Idea:
    ## 1st
        dp[i]=max(dp[i-2]+i, dp[i-1]);

00:02:  Read problem
00:11:  First implementation (some missing)
    // not considering if escape 2 house then continue rob condition
    // case 64/68 --> [2,1,1,2]  // 4
    !! Look forward
00:31:  Passed (checked solution)

# Note:

68/68 cases passed (6 ms)
Your runtime beats 16.31 % of cpp submissions
Your memory usage beats 25.79 % of cpp submissions (7.8 MB)

TC: O(N)
SC: O(N)

========================================
2022-Dec Day-14, Leetcode November Challenge Study Room Event
*/
// @lc code=end

