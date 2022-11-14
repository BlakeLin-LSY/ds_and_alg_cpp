/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution {
public:
    int n;
    int removeStones(vector<vector<int>>& stones) {
        n=stones.size();
        vector<bool> visited(n,0);
        int res=0;
        for(int i=0; i<n; ++i){
            if(visited[i]) continue;
            res+=dfs(stones, visited, i);
        }
        return res;
    }

    int dfs(vector<vector<int>>& stones, vector<bool>& visited, int index){
        visited[index]=true;
        int result=0;
        for(int i=0; i<n; ++i){
            if(!visited[i] && 
                ((stones[i][0]==stones[index][0]) ||
                 (stones[i][1]==stones[index][1]))){
                result+=dfs(stones, visited, i) + 1;
            }
        }
        return result;
    }
};
/*
:
    Remove stones as much as possible from the grid.

    Rule: 
        at least one stone in the same column / row -> the current stone can be removed.

# Idea:
    ## 1st
        Create a graph, to remove edge, until it is a leaf, find maximum steps.
    1. Create a graph
    2. Have neighbor -> step++
    3. dfs

    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. stone[i][0], stone[i][1] = x_i, y_i
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

5 min, comprehend and construct
10 min, finish idea construction (can not make it in time)

# Note:

    Reference:
        [[C++] DFS Solution 18 Lines So Simple!! + Explanations](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/solutions/787296)
        



TC: O()
SC: O()

========================================
Day-14, Leetcode November Challenge Study Room Event
*/
// @lc code=end

