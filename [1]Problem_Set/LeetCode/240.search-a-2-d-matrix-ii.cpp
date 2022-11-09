/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=m?matrix[0].size():0;
        int r=0, c=n-1;
        while(r<m && c>=0){     // Search from top-right
            int val=matrix[r][c];
            if(val==target) return true;
            else if (val<target) ++r;
            else if (val>target) --c;
        }
        return false;

    }
};
/*
:
    Search for target in a sorted matrix, with efficient algorithm

    Sorted matrix (m x n) --> 
        row(left-right) ascending
        column(top-bottom) ascending

# Idea:
    ## 1st      -> not implemented in time
        Binary search for column, then row
    1. Serch index of column, if not found or exceeded return false
    2. Search index of row

    ### Edge Case:
      1. small matrix (1x1)
      2. Large matrix (300 x 300)

    ### Key Points:
      1. Efficiency
      2. 

    ### Any Improvement Ideas / Related Questions:
      - Concise and clean
      - 

# Note:

    [Clean and concise](https://leetcode.com/problems/search-a-2d-matrix-ii/solutions/1397287/)
    [Binary Search](https://leetcode.com/problems/search-a-2d-matrix-ii/solutions/66296)

TC: O(m+n)
SC: O(1)

========================================
Day-09(extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

