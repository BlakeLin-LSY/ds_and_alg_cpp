/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        TreeNode *l=root, *r=root;
        int hl=0, hr=0;

        while(l!=NULL){
            l=l->left;
            ++hl;
        }

        while(r!=NULL){
            r=r->right;
            ++hr;
        }

        if(hl==hr){     // A perfect complete binary tree
            return (int)pow(2,hl)-1;
        }
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
/*
:
    Complete binary tree -> all the child are filled, except the last one.
# Idea:
    ## 1st
        Recursively count, count the depth
    1. n=2^(depth)-1-last_id_index
    2. 

    ### Edge Case:
      1. depth_l == depth_r --> a perfect complete binary tree
      2. 

    ### Key Points:
      1. complete binary tree must have one perfect complete binary tree child
      2. Return perfect complete binary tree count --> 2^depth-1

    ### Any Improvement Ideas / Related Questions:
      - 

# Note:
                1
            2       3
        4     5   6    7
      8  9  10

>>
            1

        2              3
      4   5          6   7
    8  9 10

>>
            2

    4           5
   8 9        10


TC: O(depth)
SC: O(depth)

========================================
Day-15, Leetcode November Challenge Study Room Event
*/
// @lc code=end

