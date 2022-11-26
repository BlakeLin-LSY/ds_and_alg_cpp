/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        for(int i=2; i<=n; ++i){
            dp[i]=i;
            for(int j=i/2; j>0; --j){
                if(i%j==0) dp[i]=min(dp[j]+i/j, dp[i]);
            }
        }
        return dp[n];
    }
};
/*
:
    Return minimum operations to reach n.
    Copy all -> one count
    Paste all -> one count

# Idea:
    ## 1st
        DP, (Kadane's algorithm?), math
    --> Simply DP and math

    ### Edge Case:
      1. n=1 -> 0
      2.

    ### Key Points:
      1. Enumerate to find pattern first
      2. i%j == 0

    ### Any Improvement Ideas / Related Questions:
      - Faster? or other algorithm?

00:03:  Read problem
00:21:  Construct idea
00:25:  Finish implementation
00:32:  Passed (+debug)

# Note:

    # Enumerate some n, to observe pattern
        n=
            1       -> 0
            2       -> 2, (1 copy, 1 paste)         AA == 2
            3       -> 3, (1 copy, 2 paste)         AAA == 3
            4       -> 4, (1 copy, 3 paste)
            5       -> 5, (1 copy, 4 paste)
            6       -> 5, (2 copy, 3 paste)         AA , AA, AA
            7       -> 7, (1 copy, 6 paste)
            8       -> 6, (2 copy, 4 paste)         AAAA, AAAA

    something like:
        dp[i] = min()
        if(i%2==0) -> min(dp[i/2]+2, n)
        if(i%j==0) -> min(dp[j]+1+(i/j)-1, n)



TC: O(N^2)
SC: O(N)

========================================
Day-26(extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

