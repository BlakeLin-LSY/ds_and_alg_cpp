// Locked question
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
public:
    vector<vector<int>> seePeople(vector<vector<int>>& heights){
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int i=0; i<m; ++i){
            stack<int> st;
            for(int j=0; j<n; ++j){
                int lastRemoved=-1;
                while(!st.empty() && heights[i][j] >= heights[i][st.top()]){
                    ans[i][st.top()]++;
                    lastRemoved=heights[i][st.top()];
                    st.pop();
                }
                if(!st.empty() && lastRemoved != heights[i][j]){
                    ans[i][st.top()]++;
                }
                st.push(j);
            }
        }

        for(int j=0; j<n; ++j){
            stack<int> st;
            for(int i=0; i<m; ++i){
                int lastRemoved=-1;
                while(!st.empty() && heights[i][j] >= heights[st.top()][j]){
                    ans[st.top()][j]++;
                    lastRemoved=heights[st.top()][j];
                    st.pop();
                }
                if(!st.empty() && lastRemoved != heights[i][j]){
                    ans[st.top()][j]++;
                }
                st.push(i);
            }
        }

        return ans;
    }
};

/*
Find "row" or "col" can see person;

    - Only to-Right, and to-Bottom direction
[
    [2, 1, 4, 3, 5],
    [3, 4, 1, 5, 2],
    [4, 5, 3, 3, 5]
]

at position(0, 0) = 2, 
    --> 2 along-row     // can see 4 at (0, 2) and 1 at (0, 1) 
    --> 1 along-col     // can see 3 at (1, 0)

    >> total == 3

Return result of this example:
[
    [3, 2, 4, 2, 2],
    [2, 3, 2, 2, 1],
    [1, 3, 1, 1, 0]
]


# Idea:
    - Two for-loop (i, j) --> in best case (reducing the duplicate comparison)
*/