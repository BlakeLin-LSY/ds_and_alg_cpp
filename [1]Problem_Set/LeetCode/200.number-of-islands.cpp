/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;

        if(grid[i][j] == '2' || grid[i][j] == '0') return;

        grid[i][j] = '2';       // Mark as visited;

        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int count=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        // cout << count << endl;
        // for(int i=0; i<n; ++i){
        //     for(int j=0; j<m; ++j){
        //         cout << grid[i][j] << ", ";
        //     }
        //     cout << endl;
        // }
        return count;
    }
};

/*
:
    Count number of islands

    island: 4-Connected pixels

# Idea:
    1. Check 4 connected-neighbor (dfs --> Time consuming)

TC:O(N*M)
SC:O(1)
*/

// @lc code=end

