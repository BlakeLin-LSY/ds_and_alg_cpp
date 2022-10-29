/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char x, y;
        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;
        for(int i=0; i<s.size(); ++i){
            x=s[i], y=t[i];
            if(mps[x]!=mpt[y]) return false;
            else{
                mps[x]=i+1;
                mpt[y]=i+1;
            }
        }
        return true;
    }
};
/*
:
    character mapping

# Trick:
    1. record last seen character index i

# Edge cases:
    1. ["badc", "babd"]     //false     -> 1-to-2 or 2-to-1 match
    2. ["paper", "title"]   //true      -> map_s can be different from mas_t

!!Note!!
    "isomorphic" here is a little vague
    only constraint is that:
        s --> t , each character in s need to be replaced with same character(1-to-1)
        t --> s , same as above;

        Confused point is:
            s & t replacement map do not have to be same! (easily confused)

TC:O(N) --> N==s.size()
SC:O(1) --> O(255) ascii characters
*/
// @lc code=end

