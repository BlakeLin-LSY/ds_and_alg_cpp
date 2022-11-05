/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
struct TrieNode{
    string word;
    TrieNode* next[26];
};

class Solution {
private:
    TrieNode* root;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>res;
        buildTrie(words);
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                backtrack(board, res, i, j, board.size() - 1, board[0].size() - 1, root);
        return res;
    }
    
    void backtrack(vector<vector<char>>& board, vector<string>& res, int r, int c, int m, int n, TrieNode* p){
        if(r < 0 || c < 0 || r > m || c > n || board[r][c] == '0'|| !p->next[board[r][c] - 'a']) return;
        p = p->next[board[r][c] - 'a'];
        if(p->word.size() > 0){
            res.push_back(p->word);
            p->word = "";
        }
        char tmp = board[r][c];
        board[r][c] = '0';
        backtrack(board, res, r - 1, c, m, n, p);
        backtrack(board, res, r + 1, c, m, n, p);
        backtrack(board, res, r, c + 1, m, n, p);
        backtrack(board, res, r, c - 1, m, n, p);
        board[r][c] = tmp;
    }
    
    void buildTrie(vector<string>& words){
        root = new TrieNode();
        for(auto x: words){
            TrieNode* p = root;
            for(auto c: x){
                if(!p->next[c - 'a']) p->next[c - 'a'] = new TrieNode();
                p = p->next[c - 'a'];
            }
            p->word = x;
        }
    }
};
/*
:


    Trie or backtrack problem, have no framework to solve it yet.

# Idea:
    [Reference]
    https://leetcode.com/problems/word-search-ii/solutions/59805/c-462-ms-brute-force-and-35-ms-trie-solution/
    
    Brute Force is not working.

    Need optimization

# Note:
    Trie (Prefix Tree)
    
TC: O()
SC: O()

========================================
Day-05, Leetcode November Challenge Study Room Event
*/
// @lc code=end

