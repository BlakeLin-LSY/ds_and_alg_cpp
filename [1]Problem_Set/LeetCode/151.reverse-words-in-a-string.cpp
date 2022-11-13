/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n=s.size();
        for(int i=0; i<n; ++i){
            while(i<n && s[i]==' ') ++i;
            int j=i;
            while(j<n && s[j]!=' ') ++j;
            if(i!=j)words.push_back(s.substr(i,j-i));
            i=j;
        }
        string res="";
        while(words.size()){
            res+=words.back();
            res+=" ";
            words.pop_back();
        }
        res=res.substr(0, res.size()-1);    // cut last space;
        return res;
    }
};
/*
:
    Reverse string words, with one space in between

# Idea:
    ## 1st
        stack, and one for-loop go through
    1. Go through string, split words
    2. concatenate words with one space

    ### Edge Case:
      1. Final space
      2. "  hello world  "      --> final with >1 spaces

    ### Key Points:
      1. Reverse words
      2. Move to next word

    ### Any Improvement Ideas / Related Questions:
      - 
      - 
2, 
8 finish implement
20 debug
# Note:

TC: O(N)
SC: O(N)

========================================
Day-13, Leetcode November Challenge Study Room Event
*/
// @lc code=end

