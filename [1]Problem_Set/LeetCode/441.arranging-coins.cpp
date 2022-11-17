/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
      long long k=sqrt(n) * sqrt(2) + sqrt(0.25) - 0.5;
      if(((k*(k+1))/2) > n ) k-=1;
      return k;
    }
};/*
    2nd visit
:
  Find the last row filled completely.

# Idea:
    ## 1st
        Math, simplify the last row, and return in O(1)
    1. Sum = (k)*(k+1)/2  
    2. Sum <= n
    3. Find closest k
    4. k^2 + k <= 2*n
    >> (k+1/2)^2 <= 2*n + 1/4
    >> k <= sqrt(2*n + 1/4) - 1/2

    ### Edge Case:
      1. Exceeded the range of int

    ### Key Points:
      1. Int range --> using long

    ### Any Improvement Ideas / Related Questions:
      - 

00:07:  Finish O(1) solution
00:08:  Passed

# Note:
    Math

1335/1335 cases passed (3 ms)
Your runtime beats 87.35 % of cpp submissions
Your memory usage beats 71.63 % of cpp submissions (5.9 MB)

TC: O(1)
SC: O(1)

========================================
Day-17(extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

