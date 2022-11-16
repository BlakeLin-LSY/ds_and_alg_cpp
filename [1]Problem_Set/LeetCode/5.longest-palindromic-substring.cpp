/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int l, r;
        string res="";
        for(int i=0; i<2*s.size(); ++i){
            l=i/2;
            r=l+i%2;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>res.size()){
                    res=s.substr(l, r-l+1);
                }
                --l, ++r;
            }
        }
        return res;
    }
};
/*
:
    Return longest palindrome string.

# Idea:
    ## 1st
        Start from 0, as a center, examine isPalindrome.
    1. Keep largest palindrome


    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. Palindrome, from center, two pointer to check s[l]==s[r]
      2. Double the i, easier to keep l and r, and Even number palindrome

    ### Any Improvement Ideas / Related Questions:
      - Clean and concise

hh:mm
00:02   : read problem
00:08   : finish and passed

# Note:

140/140 cases passed (22 ms)
Your runtime beats 80.23 % of cpp submissions
Your memory usage beats 45.94 % of cpp submissions (19.1 MB)

TC: O(N^2)
SC: O(1)
*/
// @lc code=end

