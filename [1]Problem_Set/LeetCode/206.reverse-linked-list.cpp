/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = new ListNode(0), *cur=head, *tmp;
        while(cur){
            tmp=cur->next;
            cur->next=prev->next;
            prev->next=cur;
            cur=tmp;
        }
        return prev->next;
    }
};
/*
:
    Reverse Linked List

# Idea:
    Using ListNode *tmp to store cur->next
    Update cur->next = prev
    update prev with 

# Recursive also works

TC: O(N)
SC: O(1)
*/
// @lc code=end

