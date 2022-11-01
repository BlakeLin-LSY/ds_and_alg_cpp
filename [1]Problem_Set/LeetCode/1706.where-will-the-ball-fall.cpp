/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> ans(n, -1);
        bool goNext;
        for(int i=0; i<n; ++i){
            int k=0;    // Start from the top;
            int x=i;
            goNext=true;
            while(k<m && goNext){
                int y=x+grid[k][x] ;                 // Neighbor grid, x + direction;
                if(y<0 || y>n-1) {
                    goNext=false;      // boundary
                    break;
                }
                if(grid[k][x] + grid[k][y] == 0) {
                    goNext=false;                   // \/ stop
                    break;
                }
                x=y;                                // update x to next row
                ++k;
            }
            if(k==m) ans[i]=x;
        }
        return ans;
    }
};
/*
:
    \ -> 1 (go right),
    / -> -1 (go left),
    m * n grid --> n balls falls from the top;

    return answer[i] tells if i ball goes down to the bottom successfully.
    i: i index from the top ball (if success)
    -1: failed to bottom

# Idea:
        check ball, current grid and neighbor, go next row / stop;
    1. if row[k][i]=1 -> check row[k][i+1] else check row[k][i-1]
    2. sum row[k][i] + row[k][i+1 || i-1] --> if 0 -> then stopped
    3. check k until == m;

    ## Edge Case:
        1. only one rows (base case stop)

    ## Points:
        1. one row edge case.
        2. boundary check.
        3. returned is ball index i, instead of 1 or -1;


# Note:
    Carefully the returned answer, the description is to show the ball index.
    Instead of going down successful or not...
    (Be careful not to be misleaded by example 1.  and 2.);

TC: O(m*n)
SC: O(n)

========================================
Day-01, Leetcode November Challenge Study Room Event
*/

// @lc code=end

