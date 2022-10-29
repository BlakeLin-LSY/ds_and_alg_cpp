/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lsum=0, rsum=0;
        for(auto num:nums) rsum+=num;

        for(int i=0; i<nums.size(); ++i){
            // cout << "i= " << i << " -- " << nums[i] << endl;
            if(i>0) lsum+=nums[i-1];
            rsum-=nums[i];
            // cout << lsum << ", " << rsum << endl;
            if(lsum==rsum) return i;
        }

        return -1;
    }
};
/*
:
    Find pivot which make (left_sum) == (right_sum)
    return the index of the pivot

# Idea:
    1. sum all(right_sum);
    2. split one elemnt out to left_sum;
    3. Once left_sum == right_sum --> return index;
    (4.) else check at the end, return -1;

TC:O(N)
SC:O(1)
*/
// @lc code=end

