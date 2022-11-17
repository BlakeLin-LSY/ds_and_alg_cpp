/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2){
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int curEnd=INT_MIN;
        sort(intervals.begin(), intervals.end(), comp);

        int ans=0;
        // for(auto &c:intervals){
        //     if(c[0]<curEnd) ++ans;
        //     else curEnd=c[1];
        // }
        for(int i=0; i<intervals.size(); ++i){
            if(intervals[i][0]<curEnd) ++ans;
            else curEnd=intervals[i][1];
        }
        return ans;
    }
};
/*
:
    Remove minimum interval

# Idea:
    ## 1st
        Sort intervals with interval[1], and check interval[0]<current end
    1. sort intervals
    2. compare to the current end

    ### Edge Case:
      1. Large test case?
      2. Negative value

    ### Key Points:
      1. Sort with end time
      2. 

    ### Any Improvement Ideas / Related Questions:
      - Time complexity in O(N)?

00:04:  read and first idea
00:09:  finish implementation
(debug, case 56/58) --> TLE
00:11:  Passed (modify to static comparator)

# Note:

58/58 cases passed (1004 ms)
Your runtime beats 35.18 % of cpp submissions
Your memory usage beats 82.72 % of cpp submissions (89.8 MB)

TC: O(N*logN)
SC: O(1)
*/
// @lc code=end

