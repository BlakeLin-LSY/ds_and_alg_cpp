/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size(), cols=matrix[0].size();
        int topVal;
        for(int i=0; i<rows-1; ++i){
            int j=0, k=i;
            topVal=matrix[i][j];
            while(k<rows-1 && j<cols-1){
                if(topVal!=matrix[++k][++j]) return false;
            }
        }

        for(int i=1; i<cols-1; ++i){
            int j=0, k=i;
            topVal=matrix[j][i];
            while(j<rows-1 && k<cols-1){
                if(topVal!=matrix[++j][++k]) return false;
            }
        }
        return true;
    }
};
/*
:
    Toeplitz:
        Top-left to bottom-right(diagonal) has same elements.

# Idea
    1. Directly check diagonal
    2. Diagonal index pattern i+cols, i start from 0 to rows-1;
        n_row=matrix.size();
        n_col=matrix[0].size();
    3. one for-loop + 1 while loop

TC: O(m*n)
SC: O(1)
*/
// @lc code=end

