/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(), n2=text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i=1; i<=n1; ++i){
            for(int j=1; j<=n2; ++j){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n1][n2];
    }
};
/*
:
    Longest length "common subsequence"
    (subsequence can be dis-continuous)

# Idea:
    ## 1st
        Match smaller text to larger one, else match 2 to 1
    1. Two pointer, 1 for t1, 1 for t2
    2. 

    ### Edge Case:
      1. "acab" , "ab"      --> "ab" == 2
      2. "abcad" , "dad"    --> "ad" == 2

    ### Key Points:
      1. Greedy, DP

00:02:  read problem
00:06:  first idea, but not complete 
00:12:  second idea, but not complete (store previous same character index)
00:19:  retrieve [start, end] index of 26 characters, find maximum non-overlaping count --> answer
00:24:  failed to accomplish

# Note:
    LCS, classic dp problem

    dp[i][j] == LCS of (s1[0:i] and s2[0:j])
        s1[1...i]
        s2[1...j]

    Reference:
    https://labuladong.github.io/algo/3/26/78/


45/45 cases passed (49 ms)
Your runtime beats 46.81 % of cpp submissions
Your memory usage beats 24.35 % of cpp submissions (13.1 MB)

TC: O(m*n)
SC: O(m*n)

========================================
Day-17, Leetcode November Challenge Study Room Event
*/
// @lc code=end

