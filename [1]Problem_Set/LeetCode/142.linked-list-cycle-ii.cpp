/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head, *slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(fast==slow) break;
        }

        if(fast==NULL || fast->next==NULL) return NULL;
        
        slow=head;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};
/*
:
    Find the cycle position

1. Fast, slow pointer.
2. Once fast meet slow --> cyclic exist
3. Reset slow to head, slow down fast as same speed with slow
4. second meet is the cycle start


TC: O(N)
SC: O(1)
*/
// @lc code=end

