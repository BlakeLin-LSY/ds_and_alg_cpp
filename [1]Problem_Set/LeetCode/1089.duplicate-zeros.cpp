/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cnt0=0, n=arr.size();
        queue<int> q;
        for(int i=0; i<n; ++i){
            if(arr[i]==0){
                ++cnt0;
                q.push(0);
            }
            q.push(arr[i]);
        }

        if(cnt0==0) return;
        
        for(int i=0; i<n; ++i){
            arr[i]=q.front();
            q.pop();
        }
        return;
    }
};
/*
:
    Duplicate zero, and shift the others, in-place

# Idea:
    ## 1st
        Using queue to store and check the number
    1. queue -> push numbers, if 0 appears, then push twice.
    2. Stop until reach size n

    ### Edge Case:
      1. No zeros
      2. 

    ### Key Points:
      1. In-place modification
      2. 

    ### Any Improvement Ideas / Related Questions:
      - Do it in O(1) space ?

00:03:  Read problem, and construct 1st idea
00:07:  Finish implementation
00:09:  Passed, (q.front(), q.size() -> n)

# Note:

30/30 cases passed (12 ms)
Your runtime beats 69.03 % of cpp submissions
Your memory usage beats 17.35 % of cpp submissions (10 MB)

TC: O(N)
SC: O(N)

========================================
Day-19, Leetcode November Challenge Study Room Event
*/
// @lc code=end

