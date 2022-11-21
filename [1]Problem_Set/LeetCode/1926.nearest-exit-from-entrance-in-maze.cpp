/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector <int> (n, 0));
        queue <pair<int, int>> q;
        int i = entrance[0], j = entrance[1];
		q.push({i, j});  // insert the entrance
        maze[i][j] = '+';  // mark entrance visited
		
		// 4 direction
        int    dx[] = {-1,  0,  1,  0};
        int    dy[] = { 0,  1,  0, -1};
        while(q.size()) {
            int x = q.front().first, y = q.front().second; // current cell
            q.pop();
        
            for(int i = 0; i<4; i++) {  // iterate over neighbours
				int xi = x+dx[i],  yi = y+dy[i];   // current neighbour
				
                if(xi >= 0 && xi < m && yi >= 0 && yi < n) {   // if not out of the maze
                    if(maze[xi][yi] == '.') {   // if empty
                        q.push({xi, yi});
                        dist[xi][yi] = dist[x][y] + 1;  // increment the dist from entrance
                        maze[xi][yi] = '+';  // mark visited
                        if(xi == 0 || xi == m-1 || yi == 0 || yi == n-1) {
                            return dist[xi][yi];   // if on border, return res
                        }
                    }
                }
            }
        }
        return -1;
    }
};
// /*Failed attempt*/
// class Solution {
// public:
//     int m, n;
//     vector<vector<int>> dp;
//     int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
//         m=maze.size();
//         n=maze[0].size();
//         dp.resize(m, vector<int>(n, INT_MAX));

//         for(int j=0; j<n; ++j) {
//             if(maze[0][j]=='.') dp[0][j]=0;
//             if(maze[m-1][j]=='.') dp[m-1][j]=0;
//         }
        
//         for(int i=0; i<m; ++i) {
//             if(maze[i][0]=='.') dp[i][0]=0;
//             if(maze[i][n-1]=='.') dp[i][n-1]=0;
//         }

//         for(int i=1; i<m-1; ++i){
//             for(int j=1; j<n-1; ++j){
//                 checkNeighbor(maze, i, j);
//             }
//         }

//         cout << "=========Maze=========" << endl;
//         for(auto &y:maze){
//             for(const char &x:y){
//                 cout << x << " ";
//             }cout << endl;
//         }

//         cout << "=========dp(after)=========" << endl;
//         for(auto y:dp){
//             for(auto x:y){
//                 if(x==INT_MAX) cout << -1 << " ";
//                 else cout << x << " ";
//             }cout << endl;
//         }


//         int x=entrance[0];
//         int y=entrance[1];

//         updateBorder(maze);
//         if(dp[x][y]<INT_MAX) return dp[x][y];
//         else return -1;
//     }

//     void checkNeighbor(vector<vector<char>> &maze, int i, int j){
//         int minNeighbor=INT_MAX;
//         if(maze[i][j]=='.'){
//             if(i>0) minNeighbor=min(minNeighbor, dp[i-1][j]);
//             if(i<m) minNeighbor=min(minNeighbor, dp[i+1][j]);
//             if(j>0) minNeighbor=min(minNeighbor, dp[i][j-1]);
//             if(j<n) minNeighbor=min(minNeighbor, dp[i][j+1]);
//             dp[i][j]=minNeighbor+1;
//         }   
//         return;
//     }

//     void updateBorder(vector<vector<char>> &maze){

//     }

// };
/*
:
    Return number of steps to the nearest exit (shortest path to exit)
    Grid (m x n), path (4-direction), exit == empty @ border
    '.':    empty
    '+':    wall

# Idea:
    ## 1st
        Backtrack (memo -> dp), distance to border?
        DP, go through entire grid (start from the edge, to update distance dp)
    1. dp[m][n] to store distance to exit
    2. update 4 edges first (row0, col0)
    3. 

    ### Edge Case:
      1. m, n <= 100, --> backtrack might TLE
      2. 

    ### Key Points:
      1. Return value
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

00:06:  Read problem, clarify ideas
00:44:  finish first implementation (dp way)

# Note:

    BFS Solution without Vis. Matrix (commented)
    (https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/solutions/1329141/)


TC: O(m*n*4)
SC: O(m*n)

========================================
Day-21, Leetcode November Challenge Study Room Event
*/
// @lc code=end

