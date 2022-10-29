/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();

        // Let nums1 be the smaller size;
        if(m>n) return findMedianSortedArrays(nums2, nums1);

        // Classic binary search
        int low=0, high=m;  // m is close to median, but not touched;
        while(low <= high){
            // i, j index are both 1 above the correct index;
            int i=(low+high)/2;     // index of nums1
            int j=(m+n+1)/2-i;      // index of nums2(the larger, later array)

            int l1= (i==0) ? INT_MIN:nums1[i-1];
            int l2= (j==0) ? INT_MIN:nums2[j-1];

            int r1= (i==m) ? INT_MAX:nums1[i];
            int r2= (j==n) ? INT_MAX:nums2[j];

            if(l1<=r2 && l2<=r1){
                if((m+n)%2==0){
                    return double(max(l1, l2)+min(r1, r2))/2.0;
                }else{
                    return double(max(l1, l2));
                }
            }else if(l1>l2){
                high=i-1;
            }else{
                low=i+1;
            }
        }
        return 0.0;
    }
};
/*
:
    Find median
        given 2 sorted array.

# Idea:
    1. Binary search in 2 array
    2. Note size of the array -> (m+n)  // m=nums1.size(), n=nums2.size();

    Solutions:
    [Clean](https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/2588/o-lg-m-n-c-solution-using-kth-smallest-number/)
    [Step-by-step](https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/2651020/c-solution/)
    [Choosed](https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/2536552/c-100-fastest-solution-detailed-explanation-easy-understand/)

TC:O(log(min(m,n)))
SC:O(1)
*/
// @lc code=end

