/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        string vowels="aeiouAEIOU";
        // unordered_set<char> dict(vowels.begin(), vowels.end());
        set<char> dict(vowels.begin(), vowels.end());
        int l=0, r=s.size()-1;
        while(l<r){
            while(dict.find(s[r])==dict.end() && r>0) --r;
            while(dict.find(s[l])==dict.end() && l<s.size()-1) ++l;
            if(l<r) swap(s[l++], s[r--]);
        }
        return s;
    }
};
/*
:
    Reverse the vowels

# Idea:
    ## 1st
        Two pointer (one at start, one at rear), swap values
    1. int l, r from start and end
    2. if found, swap s[l], s[r]

    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'
      2. l and r meet condition

    ### Any Improvement Ideas / Related Questions:
      - Better pointer search? or if statement?
      - 

# Note:

TC: O(N*k)  --> k is the size of possible vowels, 'aeiou' + Upper('aeiou')
SC: O(1)

========================================
Day-04, Leetcode November Challenge Study Room Event
*/
// @lc code=end

