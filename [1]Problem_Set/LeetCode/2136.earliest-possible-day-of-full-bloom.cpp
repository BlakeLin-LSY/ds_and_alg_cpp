/*
 * @lc app=leetcode id=2136 lang=cpp
 *
 * [2136] Earliest Possible Day of Full Bloom
 */

// @lc code=start
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(),
                [&](int i, int j){return growTime[i]>growTime[j];});
        
        int curTime=0, ans=0;
        for(auto i:indices){
            curTime+=plantTime[i];
            ans=max(ans, curTime+growTime[i]);
        }
        return ans;
    }
};
/*
2022-10-29 Daily challenge
*/
// @lc code=end