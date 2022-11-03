/*
 * @lc app=leetcode id=1492 lang=cpp
 *
 * [1492] The kth Factor of n
 */

// @lc code=start
class Solution {
public:
    int kthFactor(int n, int k) {
        if(--k==0) return 1;
        for(int i=2; i<=n; ++i){
            if((n%i)==0) --k;
            if(k==0) return i;
        }
        return -1;
    }
};
/*
:


# Idea:
    ## 1st
        start i from 1 to n, check if is valid factor. reaching k stop.
    1. loop from 1 to n, check modulo.
    2. if modulo == 0 , --k
    3. if k==0 return i, else -1

    ### Edge Case:
      1. k==1 --> directly return 1
      2. k-th factor == n --> note the for-loop range

    ### Key Points:
      1. modulo use
      2. 

    ### Any Improvement Ideas / Related Questions:
      - Find prime numbers (return k-th prime number)
      - 

# Note:

TC: O(n)
SC: O(1)

========================================
Day-02 (extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

