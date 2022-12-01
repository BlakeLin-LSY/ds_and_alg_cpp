/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
public:
    string vowels="aeiou";
    // string vowels="aeiouAEIOU";
    bool halvesAreAlike(string s) {
        for_each(s.begin(), s.end(), [&](char& c){c=tolower(c);});
        int l=0, r=s.size()-1;
        int cntL=0, cntR=0;
        while(l<=r){
            if(isVowel(s[l])) ++cntL;
            if(isVowel(s[r])) ++cntR;
            ++l, --r;
        }
        return cntL==cntR;
    }

    bool isVowel(char& c){
        for(auto &x:vowels) if(x==c) return true;
        return false;
    }
};
/*
:
    Two half, compare left half and right half
    (check vowels count)
    counts equal -> true, else false

# Idea:
    ## 1st
        two pointers, count vowels, note lower or upper case
    1. Turn entire string to lowercase
    2. two pointer, one from left, one from right

    ### Edge Case:
      1. s.length() -> is odd
      2. 

    ### Key Points:
      1. lower / uppercase
      2. two pointer

    ### Any Improvement Ideas / Related Questions:
      - Clean and concise?

00:02:  Read problem
00:11:  Finish implementation (Passed)

# Note:

113/113 cases passed (4 ms)
Your runtime beats 73.06 % of cpp submissions
Your memory usage beats 56.35 % of cpp submissions (6.6 MB)

TC: O(N)
SC: O(1)

========================================
2022-Dec Day-01, Leetcode November Challenge Study Room Event
*/
// @lc code=end

