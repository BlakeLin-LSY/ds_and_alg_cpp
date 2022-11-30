/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurance;
        unordered_map<int, int> occuranceUnique;
        for(auto &num:arr){
            occurance[num]++;
        }
        for(auto &[val, count]:occurance){
            if(occuranceUnique.count(count)) return false;
            else occuranceUnique[count]=val;
        }
        return true;
    }
};
/*
:
    Occurance of numbers in arr is unique -> count occurance

# Idea:
    ## 1st
        2 hash map, 1 for occurance, 1 for check unique
    
    ### Edge Case:
      1. 

    ### Key Points:
      1. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

00:02:  Read problem and example
00:07:  Finish implementation (Passed)

# Note:

64/64 cases passed (7 ms)
Your runtime beats 49.07 % of cpp submissions
Your memory usage beats 40.6 % of cpp submissions (8.2 MB)

TC: O(N)
SC: O(N)

========================================
Day-30, Leetcode November Challenge Study Room Event
*/
// @lc code=end

