/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        if(n<=1) return s;

        for(int i=1; i<s.size();){
            if(i>0 && abs(s[i]-s[i-1])==32){
                --i;
                s=s.substr(0, i) + s.substr(i+2);       // cut out s[i:i+2]
            }else ++i;
        }
        return s;
    }
};
/*
:


# Idea:
    ## 1st
        check 2 character at a time, move forward
    1. abs(s[i] - s[i-1]) == 32
    2. make sure go till the end of character

    ### Edge Case:
      1. ""             empty string
      2. "abBAcC"       all are not good
      3. "x"            single string
      4. "eAaEeE"

    ### Key Points:
      1. Good definition
      2. "A"-"a"        --> diff = 32
      3. Pair comparison, final character

    ### Any Improvement Ideas / Related Questions:
      - More concise solution
      - 

# Note:

TC: O(N)
SC: O(1)

========================================
Day-08, Leetcode November Challenge Study Room Event
*/
// @lc code=end

