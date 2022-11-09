/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root) return res;

        q.push(root);
        while(!q.empty()){
            int depth=q.size();         // queue size changed later
            TreeNode *tmp;
            vector<int> level;
            for(int i=0; i<depth; ++i){
                tmp=q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(level);
            // level.clear();
        }
        return res;
    }
};
/*
:
    Tree, level by level traverse

    --> BFS + inorder

TC: O(N)
SC: O(N)
*/
// @lc code=end

