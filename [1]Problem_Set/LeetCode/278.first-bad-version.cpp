/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1, r=n;
        int m;
        while(l<=r){
            m=l+(r-l)/2;
            if(isBadVersion(m)) r=m-1;
            else l=m+1;
        }
        return isBadVersion(l)?l:-1;
    }
};
/*
:
    Binary Search (find lower_bound)

TC: O(logN)
SC: O(1)
*/
// @lc code=end

