/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 1;
        int i=0, j=1;
        while(j<n){
            if(nums[i]==nums[j]) ++j;
            else{
                nums[++i]=nums[j++];
            }
        }
        return i+1;
    }
};/*
:
    remove duplicates in-place

# Idea:
    ## 1st
        two pointers, s[i]=s[j], ++i, ++j
    1. i index the current character, j index the next different character
    2. if s[i]==s[j] ++j, else s[i+1]=s[j], ++i, ++j;
    3. retrun s[0:i]

    ### Edge Case:
      1. all identical, j>s.size(), return s[0]
      2. 

    ### Key Points:
      1. In-place algorithm
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

# Note:

TC: O(N)
SC: O(1)

========================================
Day-11, Leetcode November Challenge Study Room Event
*/
// @lc code=end

