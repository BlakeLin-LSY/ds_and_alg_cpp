/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;

        ListNode *odd=head, *even=odd->next, *evenHead=even;
        while(even && even->next){
            odd=odd->next=even->next;
            even=even->next=odd->next;
        }
        odd->next=evenHead;
        return head;
    }
};
/*
:
    Reorder singly linked list, odd indice + even indice
    first node is odd.
    Must be O(1) space, O(N) time complexity.

# Idea:
    ## 1st
        Two pointer, Reverse linked list, Swap 1 at one time
    SC: O(N) solution, fast slow pointer, create new list, then merge two

    ### Key Points:
      1. Straight forward, connect evens and odds, then link evenHead at the tail
      
00:05:  Read problem, examples, constructing idea
00:11:  SC O(N) solution, can't figure out O(1) space 
(dropped)
00:17:  Passed

# Note:

    Reference:
    https://leetcode.com/problems/odd-even-linked-list/solutions/78287/

70/70 cases passed (26 ms)
Your runtime beats 48.8 % of cpp submissions
Your memory usage beats 75.72 % of cpp submissions (10.5 MB)

TC: O(N)
SC: O(1)

========================================
2022-Dec Day-06, Leetcode November Challenge Study Room Event
*/
// @lc code=end

