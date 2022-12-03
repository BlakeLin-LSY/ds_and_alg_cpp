/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        if(n==1) return s;

        unordered_map<char, int> freq;
        unordered_map<int, vector<char>> mp;
        vector<int> vCount;
        for(auto &c:s) ++freq[c];
        for(auto &[k, v]:freq){
            if(!mp[v].size()){
                vCount.push_back(v);
            }
            mp[v].push_back(k);
        }
        sort(vCount.begin(), vCount.end(), [&](int i, int j){return i>j;});
        string ans="";
        for(int i=0; i<vCount.size(); ++i){
            for(char &c:mp[vCount[i]]){
                for(int j=0; j<vCount[i]; ++j) ans+=c;
            }
        }
        return ans;
    }
};
/*
:
    Return sorted string with frequency count

# Idea:
    ## 1st
        Count character frequency, reorder string with frequency (high -> low)

    ### Key Points:
      0. Frequncy count
      1. Upper lower case character
      2. Sorting

    ### Any Improvement Ideas / Related Questions:
      - Could it be more concise?

00:02:  Read problem
00:10:  First implementation
00:13:  Passed (after debug)

# Note:

33/33 cases passed (42 ms)
Your runtime beats 14.03 % of cpp submissions
Your memory usage beats 40.07 % of cpp submissions (8.6 MB)

TC: O(N+k*logk)
SC: O(N)

========================================
2022-Dec Day-03, Leetcode November Challenge Study Room Event
*/
// @lc code=end

