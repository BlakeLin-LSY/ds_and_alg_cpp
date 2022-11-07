/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    static bool cmp(string &a, string &b){
        return a+b>b+a;
    }

    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> vs;
        for(auto num:nums) vs.push_back(to_string(num));

        sort(vs.begin(), vs.end(), cmp);

        if(vs[0]=="0") return "0";

        string ans="";
        for(int i=0; i<n; ++i){
            ans+=vs[i];
        }
        return ans;
    }
};
/*
:
    nums, list of positive integers, return concatenated as a string with largest number.
    [2, 3, 44,5, 9] --> "954432"

# Idea:
    ## 1st
        Sort num in nums, character by character (left to right)
    1. num to string
    2. Sort "descending" by range [0, 10), [10, 100), [100, 1000)...
    3. 

    ### Edge Case:
      1. [451, 82]          // "82451" --> though 82 < 451
      2. [99, 981, 8, 9]    // "9999818"
      3. [0]
      4. [0, 0, 0, 0]

    ### Key Points:
      1. Sort rules
      2. 

    ### Any Improvement Ideas / Related Questions:
      - 
      - 

# Note:
    No further idea, maybe Trie? (prefix, larger prefix add first)
    Reference:
    [a+b > b+a](https://leetcode.com/problems/largest-number/solutions/2618251)
    [comparator outside class](https://leetcode.com/problems/largest-number/solutions/863453)
    [lambda function](https://leetcode.com/problems/largest-number/solutions/807519)

TC: O(N*logN)
SC: O(N)    -> could be O(1), just don't store string(num) to vector

========================================
Day-07(Extra), Leetcode November Challenge Study Room Event
*/
// @lc code=end

