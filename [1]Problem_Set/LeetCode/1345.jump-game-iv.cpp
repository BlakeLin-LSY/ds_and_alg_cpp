/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

// @lc code=start
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;++i) mp[arr[i]].push_back(i);   // Index of same value arr[i]
        
        vector<int> dis(n, INT_MAX);                    // Distance to index i
        dis[0]=0;                                       // Start
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int index=q.front();
            q.pop();

            // Since the dis[index] increased one by one, once meet n-1 --> must be minimum
            if(index==n-1) return dis[index];           // Reach end index

            vector<int> &list=mp[arr[index]];
            list.push_back(index-1);
            list.push_back(index+1);                    // Neighbor possible to reach

            for(auto &x:list){
                // x in range, and have larger steps, update to current + 1 step
                if(x>=0 && x<n && dis[x]>dis[index]+1){
                    dis[x]=dis[index]+1;
                    q.push(x);
                }
            }
            list.clear();
        }
        return -1;      // Cannot read n-1
        
    }
};
/*
:
    find minimum steps to the last index.
    a[0] -> a[i0] -> a[i0-1] -> a[i1] -> a[i1-1] -> ... a[n-1]

    Rule:
        a[0] == a[i0],
        a[i0-1] == a[i1],...

# Idea:
    ## 1st
        Start from last, build a map to next same value index
    1. unordered_map<int, vector<int>> to store index of same value
    2. 

    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. Minimum steps
      2. 

    ### Any Improvement Ideas / Related Questions:
      - Visited map ? to reduce some visit
      - 

# Note:
    BFS -> queue (+ map(visited) )

    Reference:
    https://leetcode.com/problems/jump-game-iv/solutions/1690827/
    https://leetcode.com/problems/jump-game-iv/solutions/2183694/
    https://leetcode.com/problems/jump-game-iv/solutions/1692762/

TC: O(N)
SC: O(N)

========================================
Day-09(extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

