/*
 * @lc app=leetcode id=2225 lang=cpp
 *
 * [2225] Find Players With Zero or One Losses
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        map<int, int> mp;
        for(int i=0; i<n; ++i){
            if(mp[matches[i][0]]==0) mp[matches[i][0]]++;
            if(mp[matches[i][1]]==0) mp[matches[i][1]]++;
            mp[matches[i][1]]++;
        }
        vector<int> lose0, lose1;
        for(auto &[k, v]:mp){
            if(v==1) lose0.push_back(k);
            else if(v==2) lose1.push_back(k);
        }
        return {lose0, lose1};
    }
};
/*
:
    Return loss count in array

# Idea:
    ## 1st
        Count the occurances of every players, if lose -> increase count 1 more 
    1. Return count == 1 -> as answer[0]
    2. Return count == 2 -> as answer[1]

    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. Sort the index in the answer[0] and [1]
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

00:03:  Read Problem
00:18:  Finish implementation
00:25:  Fix bug (consider only have one match losers)

# Note:

127/127 cases passed (1447 ms)
Your runtime beats 39.28 % of cpp submissions
Your memory usage beats 72.24 % of cpp submissions (166.1 MB)

TC: O(N*LogN)
SC: O(N)

========================================
Day-28, Leetcode November Challenge Study Room Event
*/
// @lc code=end

