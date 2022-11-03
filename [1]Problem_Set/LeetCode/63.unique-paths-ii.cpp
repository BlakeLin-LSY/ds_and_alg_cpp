/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0]=1;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(obstacleGrid[i][j]) dp[j]=0;
                else{
                    if(j>0) dp[j]+=dp[j-1];
                }
            }
        }
        return dp[n-1];
    }
};
/*
:
    Grid path, size(m * n), obstacle[i][j] = 1 | 0, find possible path
    top-left to bottom-right.
    moving direction only right or down.

# Idea:
    ## 1st
        DP problem, define the state function
    1. dp[i][j] = dp[i-1][j]+dp[i][j-1]
    2. if(grid[i][j]==1) --> dp[i][j]=0
    3. return grid[m-1][n-1]

    ### Edge Case:
      1. m==n==1
      2. all possible path are blocked

    ### Key Points:
      1. Edge cases
      2. Simplify dp space complexity

    ### Any Improvement Ideas / Related Questions:
      - Optimize space complexity --> O(n) should be enough
      - 

# Note:
    Case 31/41
        [[0,0,0,0,0],[0,0,0,0,1],[0,0,0,1,0],[0,0,0,0,0]]   // 10
        Early stop ==> dp[j-1]==dp[j]==0 --> cannot garantee 0.

TC: O(m*n)
SC: O(n)

========================================
Day-03 (extra), Leetcode November Challenge Study Room Event
    dynamic programming, path
*/
// @lc code=end

