/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        ////  TC: O(N)
        // int k=0;
        // for(int i=1; n>=i; ++i){
        //     n-=i;
        //     ++k;
        // }
        // return k;

        // TC: O(1)
        long long k=sqrt((long)n*2);
        if((k*(k+1)/2)>n) return k-1;
        return k;
    }
};
/*
:
    Return number of complete rows where each row consist of i coins.

    A math problem,
        row1:   1 coin
        row2:   2 coins
        row3:   3 coins
        ...
        rowN:   N coins

        Sum of rows == input n value (total given coins)

# Idea:
    ## 1st
        Brute force, iterate from 1 to j, where remaining coin can complete a row.
    
    ### Edge Case:
      1. Remaining coins == next step coins
      2. large n (>10^10)

    ### Key Points:
      1. Rule of the row completion
      2. 

    ### Any Improvement Ideas / Related Questions:
      - Could be enhanced to O(1) ? --> (k)(k+1)/2 <= n --> sqrt(2*n)
      - 

4 min to have first idea
7 min finish O(N) solution and passed
12 min finish O(1) solution, 18 min passed (debug the large n)
# Note:

1335/1335 cases passed (16 ms)
Your runtime beats 25.14 % of cpp submissions
Your memory usage beats 71.62 % of cpp submissions (5.9 MB)

TC: O(N)
SC: O(1)


1335/1335 cases passed (4 ms)
Your runtime beats 77.66 % of cpp submissions
Your memory usage beats 95.05 % of cpp submissions (5.8 MB)

TC: O(1)
SC: O(1)

========================================
Day-16, Leetcode November Challenge Study Room Event
*/
// @lc code=end

