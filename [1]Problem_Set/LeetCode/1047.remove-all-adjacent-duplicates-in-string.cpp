/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();
        if(n<2) return s;
        int i=0;
        vector<char> v;
        string res="";
        while(i+1<n){
            if(s[i]==s[i+1]){
                i+=2;
            }else{
                if(v.size() >0 && v.back() == s[i]) v.pop_back();
                else v.push_back(s[i]);
                ++i;
            }
        }
        if(i<n){
            if(v.size() >0 && v.back()==s[i]) v.pop_back();
            else v.push_back(s[i]);
        }

        for(auto ch:v) res+=ch;
        
        return res;
    }
};/*
:
    Remove adjacent duplicates

# Idea:
    ## 1st
        Two pointer (i, j) comparing neighbor
    1. Compare s[i], s[j]
    2. Replace s[i+1] with s[j] if s[i]==s[i+1] && s[i]!=s[j]

    ### Edge Case:
      1. "a"            // single string
      2. "aaaaaaa"      // long and duplicates --> s.length <= 10^5, O(n) should be OK
      3. "abbaca"       // ->"aaca" -> "ca"

    ### Key Points:
      1. Return string (with no adjacent duplicates)
      2. Remove "aa" duplicates together...

    ### Any Improvement Ideas / Related Questions:
      - Faster or concise code? 
      - Remove "aA" or "Aa"... (1544. make the string great) -> similar question

# Note:

TC: O(N)
SC: O(N)

========================================
Day-09, Leetcode November Challenge Study Room Event
*/
// @lc code=end

