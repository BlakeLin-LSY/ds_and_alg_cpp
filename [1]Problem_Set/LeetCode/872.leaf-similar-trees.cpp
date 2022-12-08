/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    vector<int> leaves1, leaves2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        traverse(root1, leaves1);
        traverse(root2, leaves2);
        if(leaves1.size()!=leaves2.size()) return false;

        for(int i=0; i<leaves1.size(); ++i){
            if(leaves1[i]!=leaves2[i]) return false;
        }
        return true;
    }

    void traverse(TreeNode* node, vector<int>& leaves){
        if(!node->left && !node->right) leaves.push_back(node->val);
        else{
            if(node->left) traverse(node->left, leaves);
            if(node->right) traverse(node->right, leaves);
        }
        return;
    }
};
/*
:
    Compare two tree leaves identical.

# Idea:
    ## 1st
        Traverse tree, store leaves, do it twice, then compare

    ### Key Points:
      1. Return value
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 

00:03:  Read problem, examples
00:13:  Finish implementation (passed)

# Note:


41/41 cases passed (7 ms)
Your runtime beats 59.99 % of cpp submissions
Your memory usage beats 85.59 % of cpp submissions (12.7 MB)

TC: O(N)
SC: O(2^depth)

========================================
2022-Dec Day-08, Leetcode November Challenge Study Room Event
*/
// @lc code=end

