/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int m;
        while(l<=r){
            m=l+(r-l)/2;
            if(nums[m]==target) return m;
            else if(nums[m]>target) r=m-1;
            else if(nums[m]<target) l=m+1;
        }
        return -1;
    }
};
/*
:
    Binary Search (write it in LogN)

TC: O(logN)
SC: O(1)
*/
// @lc code=end

