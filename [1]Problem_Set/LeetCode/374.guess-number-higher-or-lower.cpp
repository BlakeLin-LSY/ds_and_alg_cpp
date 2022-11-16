/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1, r=n;
        int m;
        while(l<=r){
            m=l+(r-l)/2;
            int k=guess(m);
            if(k==0) return m;
            else if(k==-1) r=m-1;
            else if(k==1) l=m+1;
        }
        return l;
    }
};
/*
:
    Binary search, 
    -1: reduce the number
    1:  increase
    0:  the answer

# Idea:
    ## 1st
        Binary Search, start from 1 to n
    1. l=1, r=n, mid=l+(r-l)/2
    2. 

    ### Edge Case:
      1. l and r boundary condition
      2. 

    ### Key Points:
      1. Binary search, but call the api "guess()"
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 

2 min read problem
7 min finish implement and passed.

# Note:

25/25 cases passed (2 ms)
Your runtime beats 43.8 % of cpp submissions
Your memory usage beats 22.94 % of cpp submissions (5.9 MB)

TC: O(LogN)
SC: O(1)

========================================
Day-16, Leetcode November Challenge Study Room Event
*/
// @lc code=end

