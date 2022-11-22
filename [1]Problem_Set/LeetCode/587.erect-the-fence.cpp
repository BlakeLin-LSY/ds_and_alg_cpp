/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

// @lc code=start
class Solution {
public:
    // static bool comp(vector<int>& v1, vector<int>& v2){
    //     return v1[0]<v2[0]?v1[0]<v2[0]:v1[1]>=v2[1];
    // }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        // for(auto x:trees){
        //     cout << "[" << x[0] << "," << x[1] << "]"<<endl;
        // }

        // cout << "===after sort===" << endl;
        // sort(trees.begin(), trees.end(), comp);
        sort(trees.begin(), trees.end());
        // for(auto x:trees){
        //     cout << "[" << x[0] << "," << x[1]  << "]"<<endl;
        // }
        vector<vector<int>> ans;
        int n=trees.size();

        for(int i=0; i<n; ++i){
            int j=i+1;
            int maxY=trees[i][1], minY=trees[i][1];
            int m, M;
            m=i;
            M=i;
            while(j<n && trees[i][0]==trees[j][0]){
                if(trees[j][1]>maxY){
                    M=j;
                    maxY=trees[j][1];
                }
                if(trees[j][1]<minY){
                    m=j;
                    minY=trees[j][1];
                }
                ++j;
            }
            if(m!=M){
                ans.push_back(trees[M]);
            }
            ans.push_back(trees[m]);
            i=j-1;
        }
        return ans;
    }
};
/*
:
    Find minimum rope used to enclose the trees.
    Return the tree coordinates that with fence.

# Idea:
    ## 1st
        Sort with trees[i][0], find min_y, and max_y 
    1. sort x first, check same x, if tree count > 1 -> record min and max.
    2. push same x, min and max y coordinate tree to the result

    ### Edge Case:
      1. Same x, same y --> only return 2 position [x1, y1], [x2, y2]
      2. only one tree --> return 1 position

    ### Key Points:
      1. Return value
      2. 

    ### Any Improvement Ideas / Related Questions:
      -  

00:06:  read problem, constructing idea
00:18:  finish 1st implementation
00:30:  Failed to debug...

# Note:

TC: O(N*logN)
SC: O(1)

========================================
Day-20(Catch-up), Leetcode November Challenge Study Room Event
*/
// @lc code=end

