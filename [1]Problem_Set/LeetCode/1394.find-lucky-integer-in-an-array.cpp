/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 */

// @lc code=start
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0]==1 ? 1:-1;
        unordered_map<int, int> freq;
        for(auto x:arr) freq[x]++;

        int ans=-1;
        for(auto [num, count]:freq) if(num==count) ans=max(ans, num);

        return ans;
    }
};
/*
:
    Luck integer, frequency count in array == its value.
    

# Idea:
    ## 1st
        Frequency count (hash_map), 
    1. count frequency (unordered_map)
    2. check map if key == value

    ### Edge Case:
      1. [0]            // -1
      2. [1]            // 1
      3. [2,2,2,3,3]    // no lucky number

    ### Key Points:
      1. arr.size() == 1
      2. Frequency count

    ### Any Improvement Ideas / Related Questions:
      - If Lucky number > 1 ? --> store it to a vector<int>
      - if Lucky number := num^2 == count ? (or other rules)

# Note:
    Return "largest" lucky number...

TC: O(N)
SC: O(N)

========================================
Day-06(extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

