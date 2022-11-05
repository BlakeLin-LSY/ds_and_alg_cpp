/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *tmp, *half, *prev;
        tmp=head;
        half=head;
        prev=NULL;

        // half --> the slow pointer, tmp --> fast pointer
        while(tmp->next && tmp->next->next){
            tmp=tmp->next->next;
            half=half->next;
        }
        if(tmp->next) half=half->next;       // length is odd, 
                                            // we plus one further to align with even length
        // Reverse the right half part (reverse the direction)
        while(half){
            tmp=half->next;         // tmp = i+1
            half->next=prev;        // i -> i+1     -->    i |   (cut end)
            prev=half;              // | i
            half=tmp;               // i+1
        }
        half=prev;                   // reconnect to reversed head (half)
        
        // Merge two list
        while(head && half){
            tmp=head->next;
            prev=half->next;
            head->next=half;
            half->next=tmp;
            head=tmp;
            half=prev;
        }
        // even length
        if(head && head->next) head->next->next=NULL;
        return;
    }
};
/*
:
    odd index i == original order(start to end)
    even index j == reversed order(end to start)
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    [1, 10, 2, 9, 3, 8, 4, 7, 5, 6]

# Idea: (not finished, reference others)
    ## 1st
        [1, 2, 3, 4, 5] + [10, 9, 8, 7, 6]    
    1. Find the first half, with tortoies-hare approach.
    2. Reverse the right half part
    3. Merge two parts of the list


    ### Edge Case:
      1. []
      2. [1]
      3. even length of list

    ### Key Points:
      1. Linked list
      2. Reverse the linked list

    ### Any Improvement Ideas / Related Questions:
      - Already optimized 

# Note:
    - Reference Solution
    https://leetcode.com/problems/reorder-list/solutions/802983/c-hare-based-solution-explained-100-time-60-space/

TC: O(N)
SC: O(1)

========================================
Day-05(extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

