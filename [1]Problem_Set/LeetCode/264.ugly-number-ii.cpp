/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n+1, 1);
        int k=1;
        int p2=1, p3=1, p5=1;
        int v2=1, v3=1, v5=1;
        while(k<=n){
            int cur=min(min(v2, v3), v5);
            v[k]=cur;
            ++k;

            if(cur==v2){
                v2=2*v[p2];
                ++p2;
            }
            if(cur==v3){
                v3=3*v[p3];
                ++p3;
            }
            if(cur==v5){
                v5=5*v[p5];
                ++p5;
            }
        }
        return v[n];
    }
};
/*
:
    Return n-th ugly number

    entire ugly number series is combined with:
    1. 1*2 -> 2*2 -> 3*2 -> ... n*2
    2. 1*3 -> 2*3 -> 3*3 -> ... n*3
    3. 1*5 -> 2*5 -> 3*5 -> ... n*5

    ### Key Points:
      1. (2|3|5) * ugly number --> instead of increasing value
      2. Three pointer, merge three list.

# Note:

596/596 cases passed (12 ms)
Your runtime beats 78.82 % of cpp submissions
Your memory usage beats 44.65 % of cpp submissions (7.7 MB)

TC: O(N)
SC: O(N)
*/
// @lc code=end

