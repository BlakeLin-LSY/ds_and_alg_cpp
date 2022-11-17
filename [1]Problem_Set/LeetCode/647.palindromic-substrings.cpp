/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        int l, r;
        for(int center=0; center<2*s.size(); ++center){
            l=center/2;
            r=l+center%2;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                ++res;
                --l, ++r;
            }
        }
        return res;
    }
};
/*
:
    Find all subset of palindrome

# Idea:
    ## 1st
        Brute force for all

    ### Edge Case:
      1. Even and Odd number of palindrome

    ### Key Points:
      1. From center -> No need to worry duplicates, because "different center"
      2. 

    ### Any Improvement Ideas / Related Questions:
      - To do this problem using DP?

00:01:  Read problem
00:04:  Finish implementation
00:05:  Passed

# Note:

130/130 cases passed (7 ms)
Your runtime beats 73.36 % of cpp submissions
Your memory usage beats 81.49 % of cpp submissions (6.2 MB)

TC: O(N^2)
SC: O(1)
*/
// @lc code=end

