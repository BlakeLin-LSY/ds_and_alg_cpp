/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy=ListNode(0);
        ListNode* cur=&dummy;
        while(list1 && list2){
            if(list1->val <= list2->val){
                cur->next=list1;
                list1=list1->next;
            }
            else {
                cur->next=list2;
                list2=list2->next;
            }
            cur=cur->next;
        }
        cur->next = list1 ? list1:list2;
        return dummy.next;
    }
};
/*
:
    Merge two sorted list (data structure -> linked list)

# Idea:
    ## 1st
        Create a dummy node, two pointers to compare value
    1. Gothrough node1, and node2 to the end

    ### Edge Case:
      1. Base case (zero or one for the input size)
      2. 

    ### Key Points:
      1. Dummy node to start (later can return)
      2. Two pointers
      3. Pointer use (-> or .)

    ### Any Improvement Ideas / Related Questions:
      - If not sorted list, how to merge?
      >> Sort linked list first ( since linked list goes one direction)
      
      Split to 2 sub question:
      1. Sort linked list 
      2. merge two sorted linked list (this problem)

      ? How to sort linked list ?
        My 1st Idea: --> Merge sort basically;  TC: O(N*logN)
            1. Split to two (and more) sub sorted linked list
            2. Merge them;

            Key issue --> N pointers to compare;
        
        Other Ideas: TC: O(N^2)
            1. Swap value (bubble sort)
            2. Insertion sort (https://www.interviewkickstart.com/problems/sort-list)

# Note:
    1. 
        ListNode dummy = ListNode(0);
        ListNode* ans = &dummy;         // Reference
    2. Add the rest directly (no need to go while loop)

TC: O(m+n)
SC: O(1)

========================================
Day-03, Leetcode 75
    Linked List, two pointers
*/
// @lc code=end

