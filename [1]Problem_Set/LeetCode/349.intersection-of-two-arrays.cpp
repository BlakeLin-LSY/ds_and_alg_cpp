/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(!nums1.size() || !nums2.size()) return {};
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());

        vector<int> ans;
        for(int x:set2){
            if(set1.count(x)) ans.push_back(x);
        }
        return ans;
    }
};/*
:
    Set, union

# Idea:
    ## 1st
        Set and find union of two sets
    1. 
    2. 

    ### Edge Case:
      1. Empty
      2. 

    ### Key Points:
      1. Using set
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

# Note:
    https://cplusplus.com/reference/set/

TC: O(N)    -> to store in set
SC: O(N)    -> to store set

========================================
Day-12(extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

