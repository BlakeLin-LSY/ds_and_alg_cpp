/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        //Converts the connections to an adjaceny list representation 
        //Time complexity = O(E)
        for(int i=0; i<connections.size(); i++){
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> discoveryTime(n, INT_MAX); //Time complexity = O(V)
        vector<int> lowTime(n, INT_MAX); //Time complexity = O(V)
        vector<bool> visited(n, false); //Time complexity = O(V)
        int startTime = 0;
        //Time complexity = O(V+E)
        dfs(adjList, visited, discoveryTime, lowTime, 0, -1, startTime);
        return res;
    }

    void dfs(vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& discTime,
             vector<int>& lowTime, int src, int parent, int& time){
        visited[src] = true;
        discTime[src] = time++;
        lowTime[src] = discTime[src];
        for(int i=0; i<adjList[src].size(); i++){
            //If the adjacent node is parent dont traverse
            if(adjList[src][i] == parent){continue;}
            //If the adjacent node is already visited then that means there was a path to the adjacent
			//node that doesnt come from this source directly i.e an alternate path to this node from the
			//source. If there is one path already connecting the present source and its neighbour then the
			//removal of this edge wont create a seperation for sure. Hence we just check if this neighbour
			//node has a back edge and updates lower time.
            else if(visited[adjList[src][i]]){
                lowTime[src] = min(lowTime[src], lowTime[adjList[src][i]]);
            //If the node is not visited by any other node we visit.
            } else {
                dfs(adjList, visited, discTime, lowTime, adjList[src][i], src, time);
                lowTime[src] = min(lowTime[src], lowTime[adjList[src][i]]);
                //If the neighbour had a back edge to atleast one of the ancestors of this source then the
				//lowTime of the neighbour will either be lower or equal to discoveryTime of source. If not 
				//its surely a cut edge.
                if(discTime[src]<lowTime[adjList[src][i]]){
                    res.push_back({src, adjList[src][i]});
                }
            }
        }

    }
};
/*
:
    Graph, find edge leaf

# Idea:
    ## 1st
        Backtrack, dfs, with connection -> to find leaf
    1. Create a visited map
    2. 

    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. Return value
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

2 min read
9 min finish first implement.
Not comeplete enough --> thinking too easy

# Note:
    Not only the edge -> find the "Bridge"

    Reference:
    https://leetcode.com/problems/critical-connections-in-a-network/solutions/763186

TC: O(V+E)  -> Vertex, Edge
SC: O()

========================================
Day-15(extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

