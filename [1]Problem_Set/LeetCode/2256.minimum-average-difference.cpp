/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 */

// @lc code=start
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long lSum=0, rSum=0;
        int ans=0, curMin=INT_MAX;
        for(auto &num:nums) rSum+=num;
        for(int i=0; i<n; ++i){
            lSum+=nums[i];
            rSum-=nums[i];
            int tmp=(lSum/(i+1));
            if(n-i-1>0) tmp-=(rSum/(n-i-1));

            if(tmp<0) tmp*=(-1);
            else if(tmp==0) return i;

            if(tmp<curMin){
                curMin=tmp;
                ans=i;
            }
        }
        return ans;
    }
};
/*
:


# Idea:
    ## 1st
        Two pointer, dp

    ### Edge Case:
      1. [0]
      2. Divide by 0

    ### Key Points:
      1. Minimum difference is 0
      2. could be overflow -> 10^5 * 10^5 > 10^9
      3. 

    ### Any Improvement Ideas / Related Questions:
      - 
      
00:02:  Read problem
00:08:  First Implementation
(check)
00:18:  Double check, and modify
00:22:  Passed

# Note:

78/78 cases passed (263 ms)
Your runtime beats 59.36 % of cpp submissions
Your memory usage beats 54.89 % of cpp submissions (78.4 MB)

TC: O(N)
SC: O(1)

========================================
2022-Dec Day-04, Leetcode November Challenge Study Room Event
*/
// @lc code=end

