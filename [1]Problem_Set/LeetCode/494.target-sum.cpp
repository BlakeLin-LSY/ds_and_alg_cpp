/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0; 
        for (int n : nums) sum += n; 
        // 這兩種情況，不可能存在合法的子集劃分 
        if (sum < abs(target) || (sum + target) % 2 == 1) { 
            return 0; 
        }
        // nums中存在幾個子集A，使得 A 中元素的和為(target + sum(nums)) / 2
        return subsets(nums, (sum + target) / 2);
    }

    int subsets(vector<int>& nums, int sum){
        /*
        ```
        nums:   each backpack wight
        sum:    total weight
        ```
        */
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        // base case
        dp[0][0]=1;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=sum; ++j){
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];                    
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};
/*
:
    nums of array (integer)
    combination of expression for each number to make final sum == target

# Idea:
    # Backtrack
        TC: O(2^m) -> backtrack
        SC: O(1)
        
        139/139 cases passed (1375 ms)
        Your runtime beats 19.5 % of cpp submissions
        Your memory usage beats 93.97 % of cpp submissions (8.9 MB)

    # Backtrack + Memo
        TC: O(2^m) -> backtrack
        SC: O(m)

        139/139 cases passed (1002 ms)
        Your runtime beats 22.67 % of cpp submissions
        Your memory usage beats 6.26 % of cpp submissions (89.8 MB)

    # DP -> Backpack
    :
        如果我們把 nums 劃分成兩個子集 A 和B，
        分別代表分配 + 的數和分配 - 的數，那麼他們和 target 存在如下關係：
        ```
            sum(A) - sum(B) = target
            sum(A) = target + sum(B)
            sum(A) + sum(A) = target + sum(B) + sum(A)
            2 * sum(A) = target + sum(nums)
        ```

        nums中存在幾個子集A，使得 A 中元素的和為(target + sum(nums)) / 2
        dp[N][sum]，即使用所有 N 個物品，有幾種方法可以裝滿容量為 sum 的背包


        139/139 cases passed (31 ms)
        Your runtime beats 62.11 % of cpp submissions
        Your memory usage beats 43.65 % of cpp submissions (12.2 MB)
        
        TC: O(N*sum)
        SC: O(N*sum)    -> this can further reduced to O(sum)
    

00:03:  Read the problem
00:15:  Can't figure out dp solution --> dropped.


# Note:
    Reference:
    https://labuladong.github.io/algo/3/27/84/



========================================
Day-18, Leetcode November Challenge Study Room Event
*/
// @lc code=end

