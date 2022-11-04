/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */

// @lc code=start
class Solution {
public:
    int maxPower(string s) {
        int ans=INT_MIN;
        int count=1;            // Since s.size() >=1 --> garantee must 1 consecutive
        for(int i=1; i<s.size(); ++i){
            if(s[i]==s[i-1]) ++count;
            else{
                ans=max(ans, count);
                count=1;
            }
        }
        return max(ans, count); // Edge case "aaaaaaaa"
    }
};
/*
:
    Find consecutive character count.

# Idea:
    ## 1st
        dp(two pointer is fine), for-loop
    1. record prev_c, count, max_c
    2. once prev_c!=cur_c -> update max_c

    ### Edge Case:
      1. all character are the same
      2. 

    ### Key Points:
      1. initial count and for loop start i.
      2. No consecutive characters (initial count)

    ### Any Improvement Ideas / Related Questions:
      - consecutive numbers

# Note:

TC: O(N)
SC: O(1)

========================================
Day-04(extra), Leetcode November Challenge Study Room Event
    two pointer, dp
*/
// @lc code=end

