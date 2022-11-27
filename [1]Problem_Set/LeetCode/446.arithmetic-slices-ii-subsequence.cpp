/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<long, int>> dp(n);    // {diff, same count}
        int ans=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                long diff=(long)nums[i]-nums[j];

                if(dp[j].count(diff)){
                    dp[i][diff]+=dp[j][diff];   // add previous dp[j][diff] count
                    ans+=dp[j][diff];           // three numbers, with 2 same diff
                }
                dp[i][diff]+=1;     // End at i(num2), with diff -> [num1, num2]
            }
        }
        return ans;
    }
};
/*
:
    arithmetic subsequences -> 
    1. arithmetic:
        difference of any two consecutive element is the same
    2. subsequence: (len >= 3)
        Subset of original sequence (order not modified, but can jump)

# Idea:
    ## 1st
        Brute force -> backtrack, --> further (dp)

00:04:  Read problem
00:30:  Constructing idea
00:40:  Failed to accomplish in time

# Note:

    Find difference, using difference as index to find next.

    Create a map like:
    [2, 4, 6, 8, 10]
    i=0 : [2, 4, 6, 8]    --> [4-2, 6-2, 8-2, 10-2]
    i=1 : [2, 4, 6]       --> [6-2, 8-2, 10-2]
    i=2 : [2, 4]          --> [8-2, 10-2]
    i=3 : [2]             --> [10-2]

    vector<map<int, vector<int>>> --> every map stores { difference , [index]}

    Check keys in the map index, store it to a temp vector, 
    if temp.size() >= 3 -> ans += (temp.size()-3+1)!;
    mark difference as visited.

    Complexity:
        N * (N-1) to create the vector<map>



TC: O(N^2)
SC: O(N^2)

========================================
Day-27, Leetcode November Challenge Study Room Event
*/
// @lc code=end

