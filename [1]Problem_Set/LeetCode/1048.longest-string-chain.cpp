/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
public:
    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int ans=1;
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), comp);
        for(auto word:words){
            dp[word]=1;     // Add to dp
            for(int i=0; i<word.size(); ++i){
                string prev=word.substr(0, i)+word.substr(i+1);   // remove index i character;
                if(dp.find(prev)!=dp.end()){
                    dp[word]=max(dp[word], dp[prev]+1);
                }
            }
            ans=max(ans, dp[word]);
        }
        return ans;
    }
};
/*
:


# Idea:
    ## 1st
        monotonic stack, dfs -> wrong direction

    ### Key Points:
      1. Recursively solve the problem(split it to sub-problem)
      2. Add one character -> remove one character (to reduce the complexity)

    ### Any Improvement Ideas / Related Questions:
      - 

00:04:  Read problem
00:08:  Finish first construct (failed)

1, 2, 3,...16 -> maximum return value
C(1000, 16) -> maximum combinations

sort first(by words[i].length)
# Note:
    "Finding longest" --> optimization problem, using DP



    Edge case 80/82:
    ["c","cd","ab","bcd","abc","abcd","abcde"]
    >>      5

    update dp[word] with maximum value, else causing error.

    Reference:
    ✅ [C++/Python] Simple Solution w/ Explanation | DP
    (https://leetcode.com/problems/longest-string-chain/solutions/2153007/)
    [Java/C++/Python] DP Solution
    (https://leetcode.com/problems/longest-string-chain/solutions/294890/)

82/82 cases passed (114 ms)
Your runtime beats 86.79 % of cpp submissions
Your memory usage beats 46.81 % of cpp submissions (17.4 MB)

TC: O(N*logN)
SC: O(N*16)

========================================
Day-20(catch-up), Leetcode November Challenge Study Room Event
*/
// @lc code=end

