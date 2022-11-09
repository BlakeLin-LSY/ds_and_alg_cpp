/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        traverse(root);
        return res;
    }
    void traverse(Node* root){
        if(!root) return;

        res.push_back(root->val);
        for(auto child:root->children){
            traverse(child);
        }
    }
};
/*
:
    N-ary Tree Preorder traversal

    root | children_0 | children_1...


TC: O(N)
SC: O(N)    --> call traverse() extra space
*/
// @lc code=end

