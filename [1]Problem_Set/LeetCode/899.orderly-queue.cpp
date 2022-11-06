/*
 * @lc app=leetcode id=899 lang=cpp
 *
 * [899] Orderly Queue
 */

// @lc code=start
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==0) return s;
        else if(k==1){
            string ss=s+s;
            for(int i=1; i<s.size(); ++i){
                s=min(s, ss.substr(i, s.size()));
            }
        }else{          // k>1 : always give a sorted string
            sort(s.begin(), s.end());
        }
        return s;
        
    }
};
/*
:


# Idea:
    ## 1st
        Make first k letters as small as possible,
    1. Find the pattern (using k as a index)
    2. k==1 --> find the smallest string

    ### Edge Case:
      1. k==0
      2. k==1

    ### Key Points:
      1. Return result, if (k>1) --> always give a "sorted" string
      2. SS = s+s       // traverse the string
      3. min(tmps, SS.substring(i, s.size())) --> gives the smallest lexicographically string

    ### Any Improvement Ideas / Related Questions:
      - Already optimized

# Note:
    [Reference](https://leetcode.com/problems/orderly-queue/solutions/2778309/faster-than-100-0ms/)

    **s.substr(i) --> s[i=start] till end of string s
    **s.substr(i, n) --> s[i=start, n=length]

TC: O(N) for k==0,  O(N*logN) for k>1 --> sort takes O(N*logN)
SC: O(1)

========================================
Day-06, Leetcode November Challenge Study Room Event
*/
// @lc code=end

