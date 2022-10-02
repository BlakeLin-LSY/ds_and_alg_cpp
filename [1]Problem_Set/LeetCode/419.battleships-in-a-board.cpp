/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        int count=0;

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(board[i][j]=='.') continue;
                if(i > 0 && board[i-1][j] == 'X') continue;
                if(j > 0 && board[i][j-1] == 'X') continue;
                count++;
            }
        }
        return count;

        // vector<int> row(m, 0);
        // vector<vector<int>> Board(n, row);

        // cout << "n, m = " << n << ", " << m << endl;
        // for(int i=0; i<n; ++i){
        //     for(int j=0; j<m; ++j){
        //         cout << Board[i][j] << ", ";
        //     }
        //     cout << endl;
        // }

        // return 0;
    }
};
// @lc code=end

