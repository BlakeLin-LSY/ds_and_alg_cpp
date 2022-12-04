/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;     // prefixsum -> j index
        mp[0]=-1;
        int presum=0, ans=0;
        for(int i=0; i<n; ++i){
            if(nums[i]==0) presum-=1;
            else presum+=1;

            if(mp.find(presum)!=mp.end()){
                ans=max(ans, i-mp[presum]);
            }else{
                mp[presum]=i;
            }
        }
        return ans;
    }
};
// Failed solution (idea not complete)
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n+1, 0);
//         int cnt0=0, cnt1=0;
//         for(int i=0; i<n; ++i){
//             if(nums[i]==0) ++cnt0;
//             else ++cnt1;
//             if(abs(cnt0-cnt1)>1) dp[i]=dp[i-1];
//             else dp[i]=min(cnt0, cnt1);
//         }
//         return dp[n-1]<<1;
//     }
// };
/*
:
    Maximum "contiguous subarray" length (with equal 1 and 0 numbers)

# Idea:
    ## 1st
        Count 1 and 0 frequncy, find longest contiguous 1s or 0s
        
    ## 2nd (dp way)
        start from end, count pre 1 and 0 frequency, dp[i] is min(freq[0], freq[1]).

    ### Edge Case:
      1. [0,1,1,0,1,1,1,0]
      2. [0,0,1,0,0,0,1,1]

    ### Key Points:
      1. Subarray sum[j:i] ==> prefixsum[i]-prefixsum[j-1]
      2. beginning of the prefixsum[0]=-1       // Create virtual beginning
      3. Must be O(N) -> else TLE

00:03:  Read problem and examples
00:09:  Finish implementation
00:15:  Failed, some edge case not considered

# Note:

    Reference:
    [【每日一题】LeetCode 525. Contiguous Array](https://youtu.be/uYuSLvjEyjQ)

564/564 cases passed (270 ms)
Your runtime beats 59.53 % of cpp submissions
Your memory usage beats 52.68 % of cpp submissions (83.9 MB)

TC: O(N)
SC: O(1)
*/
// @lc code=end

