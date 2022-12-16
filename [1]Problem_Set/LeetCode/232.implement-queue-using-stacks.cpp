/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
public:
    stack<int> st1, st2;    // st1 in queue, st2 out queue
    MyQueue() {}
    
    void push(int x) {
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int out=st2.top();
        st2.pop();
        return out;
    }
    
    int peek() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/*
:
    Using only 2 stacks to implement queue.

# Idea:
    ## 1st
        Stack to implement queue -> 
        1 stack reverse the order, the 2nd one reverse(reverse) --> become queue(FIFO)


    ### Key Points:
      1. Return value
      2. 

    ### Any Improvement Ideas / Related Questions:
      - A little redundant?
      - 

00:04:  Read problem
00:09:  Finish 1st implementation
00:18:  Debug (return value, pop and peek)
00:27:  Reorganize idea (wrong at 1st idea)
    // stack 1 for input 
    // stack 2 for output
00:28:  Passed

# Note:

22/22 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 11.41 % of cpp submissions (7.1 MB)

TC: O(N)
SC: O(N)

========================================
2022-Dec Day-16, Leetcode November Challenge Study Room Event
*/
// @lc code=end

