/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    int m, n;
    int dx[4]={0, 1, 0, -1};
    int dy[4]={1, 0, -1, 0};
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        int k=word.size();
        if(k > m*n) return false;     // Prune 1.

        // Prune 2: the arr does not contain all occurrences of the chars in the word.
        unordered_map<char, int> occ;
        for (auto& r : board) for (auto& c : r) ++occ[c];
        for (auto& c : word) if(--occ[c] < 0) return false;

        // Prune 3: Find the longest prefix/suffix of the same character. If the longest
        // suffix is longer than the longest prefix, swap the strigns (so we are less
        // likely to have a long prefix with a lot of the same character).
        int left = word.find_first_not_of(word[0]);
        int right = k - word.find_last_not_of(word[k - 1]);
        if (left > right) reverse(begin(word), end(word));

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(dfs(board, i, j, word)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, string &word){
        if(word.size()==0) return true;
        if(i<0 || i>=m || j<0 || j>=n) return false;

        char tmp=board[i][j];
        if(tmp!=word[0]) return false;
        board[i][j]='#';
        string s=word.substr(1);
        bool res=false;
        for(int k=0; k<4; ++k){
            res|=dfs(board, i+dx[k], j+dy[k], s);
        }
        board[i][j]=tmp;
        return res;
    }
};
/*
:


# Idea:
    ## 1st
        DFS, backtrack, (queue + dfs)
    1. Find first character in board, add to queue
    2. start with character in queue, and find next (neighbor), record visited
    3. go through entire queue, if not complete match target word, then return false

    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. word consist english letters (lower and upper cases)
      

00:01:  Read problem
00:24:  1st implementation(dfs + backtrack), stuck in visited path
00:32:  No progress

# Note:

    Reference:
    https://leetcode.com/problems/word-search/solutions/1330278/
    https://leetcode.com/problems/word-search/solutions/2094020

    
    Prune 3 is for such cases
    [["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"]]
    "AAAAAAAAAAAAAAB"
    it changes word to "BAAAAAAAAAAAAAA"

## After prunes
84/84 cases passed (6 ms)
Your runtime beats 99.16 % of cpp submissions
Your memory usage beats 17.64 % of cpp submissions (8.1 MB)


84/84 cases passed (718 ms)
Your runtime beats 49.49 % of cpp submissions
Your memory usage beats 46.96 % of cpp submissions (8.1 MB)

TC: O(m*n*k) -> worst case, k is the length of word
SC: O(k)

========================================
Day-24, Leetcode November Challenge Study Room Event
*/
// @lc code=end

