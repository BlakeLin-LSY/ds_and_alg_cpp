/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1=word1.size(), n2=word2.size();
        if(n1!=n2) return false;

        unordered_map<int, int> mp1, mp2;
        for(int i=0; i<n1; ++i){
            ++mp1[word1[i]-'a'];
            ++mp2[word2[i]-'a'];
        }

        if(mp1.size()!=mp2.size()) return false;
        set<int> ch26;
        unordered_map<int, vector<int>> cnt1, cnt2;
        for(auto &[k, v]:mp1) {
            cnt1[v].push_back(k);
            ch26.insert(k);
        }
        for(auto &[k, v]:mp2) {
            cnt2[v].push_back(k);
            ch26.erase(k);
        }

        if(ch26.size()!=0) return false;
        if(cnt1.size()!=cnt2.size()) return false;
        for(int i=1; i<=cnt1.size(); ++i){
            if(cnt1[i].size()!=cnt2[i].size()) return false;
        }
        return true;
    }
};
/*
:
    Close definition:
    1. 1 swap to make identical
    2. character transform (a <-> b)

# Idea:
    ## 1st
        Only count matters, Comparing set count?
    1. ch1[26], ch2[26] to store word1, word2 character counts
    2. sort ch1[26], ch2[26] then compare two array

    ### Edge Case:
      1. word1.size() != word2.size()
      2. count are the same, but cannot transform to another

    ### Key Points:
      1. Return value
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

00:05:  Read problem and example
00:24:  First intuitive implementation (having some edge case not considered)
(Debug, add another hash map)
00:45:  Struggle at comparing
00:50:  (dropped)

# Note:
    "2. Transform 'every occurrence' of one 
                'existing' character into 'another existing' character,"

Case 130/152:
    "uau"
    "ssx"
    >> false

152/152 cases passed (539 ms)
Your runtime beats 5.09 % of cpp submissions
Your memory usage beats 5.39 % of cpp submissions (154.9 MB)

TC: O(N)
SC: O(N)

========================================
2022-Dec Day-02, Leetcode November Challenge Study Room Event
*/
// @lc code=end

