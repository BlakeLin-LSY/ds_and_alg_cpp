/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int ans=0, MOD=1e9+7;
        stack<int> st;      // Stores index of arr local minimum
        vector<int> h(n);   // Stores lowest index, -1 means itself is the minimum

        for(int i=n-1; i>=0; --i){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            h[i]=st.empty()? -1:st.top();
            st.push(i);
        }

        for(int i=n-1; i>=0; --i){
            if(h[i]==-1){
                arr[i]*=(n-i);
            }else{
                arr[i]*=(h[i]-i);
                arr[i]+=arr[h[i]];
            }
            ans+=arr[i];
            ans%=MOD;
        }
        return ans;
    }
};
/*
:
    Sum of all the contiguous subarray min value.

# Idea:
    ## 1st
        Go through N (number of arr), N, N-1, N-2..., keep min value
    1. Two for loop, (i, j)
    2. step2...

    ### Edge Case:
      1. 73/87 --> large and long arr, overflow     // ans: 508796209
      2. 

    ### Key Points:
      1. Overflow
      2. DP strategy

    ### Any Improvement Ideas / Related Questions:
      - 
      - 
00:04:  Read problem, 1st idea
00:07:  Finish first implementation
00:16:  Debug...(cast 73/87)
00:18:  No idea to fix the overflow --> wrong MOD = 1e9+7 (wrong set to 10e9+7)
00:21:  78/87 case --> TLE (TC: O(N^2))

int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(), curMin;
        int res=0;
        int MOD=1e9+7;
        for(int i=0; i<n; ++i){
            curMin=arr[i];
            curMin%=MOD;
            res%=MOD;
            res+=curMin;

            for(int j=i+1; j<n; ++j){
                curMin=min(curMin, arr[j]);
                curMin%=MOD;
                res%=MOD;
                res+=curMin;
            }
        }
        return res;
    }

# Note:
    Reference:
    O(N) 
    [monotonic stack](https://leetcode.com/problems/sum-of-subarray-minimums/solutions/1077526/)


87/87 cases passed (215 ms)
Your runtime beats 57.94 % of cpp submissions
Your memory usage beats 78.86 % of cpp submissions (40.9 MB)

TC: O(N)
SC: O(N)

========================================
Day-25, Leetcode November Challenge Study Room Event
*/
// @lc code=end

