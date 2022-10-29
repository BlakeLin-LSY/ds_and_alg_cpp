/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1; i<nums.size(); ++i) nums[i]+=nums[i-1];
        return nums;
    }
};
/*
:
    Intuitive --> directly add num[i-1] to num[i]

# Other's solution
    [Less_variables](https://leetcode.com/problems/running-sum-of-1d-array/solutions/2096022/c-short-easy-w-prefix-sum-partial-sum-stl/)

TC:O(N)
SC:O(1)
*/
// @lc code=end

