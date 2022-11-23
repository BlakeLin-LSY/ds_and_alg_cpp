/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, int> row, col, block;
        int n=board.size();

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j]=='.') continue;
                
                string key_r=to_string(i)+","+board[i][j];
                string key_c=to_string(j)+","+board[i][j];
                int block_id=((i/3)%3)*3 + ((j/3)%3);
                string key_b=to_string(block_id)+","+board[i][j];

                if(row[key_r]) return false;
                else ++row[key_r];

                if(col[key_c]) return false;
                else ++col[key_c];
                
                if(block[key_b]) return false;
                else ++block[key_b];
            }
        }

        return true;
    }
};
/*
:
    Check sudoku valid or not (only the existing numbers)

# Idea:
    ## 1st
        row, col, block(3 x 3)
    1. Create 3 hash-table, 1 for row, 1 for col, 1 for block
    2. 


    ### Key Points:
      1. row, col, block index check
      2. 

    ### Any Improvement Ideas / Related Questions:
      - Other elegant solution?

00:03:  read problem
00:17:  finish implementation
00:25:  Passed (after debug, key bug...)

# Note:

507/507 cases passed (34 ms)
Your runtime beats 77.17 % of cpp submissions
Your memory usage beats 17.32 % of cpp submissions (20.7 MB)

TC: O(N*N)
SC: O(N*N)

========================================
Day-23, Leetcode November Challenge Study Room Event
*/
// @lc code=end

