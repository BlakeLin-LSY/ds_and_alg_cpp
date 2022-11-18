/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        if(n<=6) return true;

        if(n%5==0) return isUgly(n/5);
        else if(n%3==0) return isUgly(n/3);
        else if((n&1)==0) return isUgly(n>>1);
        else return false;

    }
};
/*
:
    integer( >0 ), prime factors [2 | 3 | 5] only. -> true, else false;
    Math -> sieve
    2: last digit [2, 4, 6, 8, 0]
    3: sum of total digits % 3 == 0
    5: last digit [0, 5]

# Idea:
    ## 1st
        check digits
    0. check >0
    1. first 2, then 5
    2. check digits from end, check if %3

    ### Edge Case:
      1. negative number (-2^31)
      2. large number (2^31-1)
      3. 1      // true
      4. 0      // false

    ### Key Points:
      1. (n&1)==0  --> can not written in  n&1==0

    ### Any Improvement Ideas / Related Questions:
      - 

00:04:  read problem, construct first idea
00:08:  finish implementation
00:14:  debug -> edge case "1", problem misunderstanding
00:23:  Stuck, then drop to restart

# Note:
    1. Edge case
    2. Understanding the problem -> 2, 3, 5 --> other than these primes -> true

1013/1013 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 69.56 % of cpp submissions (5.9 MB)

TC: O(log_5(N)) --> O(log_2(N) + log_3(N) + log_5(N))
SC: O(N)

========================================
Day-18, Leetcode November Challenge Study Room Event
*/
// @lc code=end

