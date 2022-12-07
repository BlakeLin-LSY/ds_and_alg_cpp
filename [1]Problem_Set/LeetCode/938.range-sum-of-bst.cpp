/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    int ans=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return ans;
    }

    void dfs(TreeNode* node, int low, int high) {
        if(!node) return;

        int v=node->val;
        if(v>high){
            dfs(node->left, low, high);
        }else if(v<low){
            dfs(node->right, low, high);
        }else{
            ans+=node->val;
            dfs(node->left, low, high);
            dfs(node->right, low, high);
        }
        return;
    }
};
/*
:
    Sum up all the values in range [low, high]

# Idea:
    ## 1st
        Traversal tree node, dfs

    ### Key Points:
      1. Tree traversal

    ### Any Improvement Ideas / Related Questions:
      - Cleaner logics


00:02:  read problem
00:07:  Finish first implementation (dfs)
00:10:  Run test cases, debug (Passed)

# Note:

41/41 cases passed (143 ms)
Your runtime beats 87.57 % of cpp submissions
Your memory usage beats 18.63 % of cpp submissions (64.8 MB)

TC: O(N)
SC: O(N)

========================================
2022-Dec Day-07, Leetcode November Challenge Study Room Event
*/
// @lc code=end

