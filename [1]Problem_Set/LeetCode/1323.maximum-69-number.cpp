/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
public:
    int maximum69Number (int num) {
        int remain=num;
        vector<int> digits;
        while(remain){
            digits.push_back(remain%10);
            remain/=10;
        }
        for(int i=digits.size()-1; i>=0; --i){
            if(digits[i]==6) {
                num+=3*pow(10,i);
                break;
            }
        }
        return num;
    }
};
/*
:
    num [6 or 9], change "at most 1" digit, return Maximum num

# Idea:
    ## 1st
        straight forward, find first 6, and change it to 9 --> gives largest num in return
    1. Loop through left to right
    2. Once find 6, then change it to 9
    3. (since it's int, check digit(character) by using modulo 10)

    ### Edge Case:
      1. num only have 1 -> simple case
      2. large num --> (num <= 10^4) it's okay, no worry

    ### Key Points:
      1. num to string / digits
      2. digit traversal

    ### Any Improvement Ideas / Related Questions:
      - Concise and clean?
      - O(1) space complexity?

# Note:

    [Fxxking straight forward...](https://leetcode.com/problems/maximum-69-number/solutions/2733230)
    [to_string](https://leetcode.com/problems/maximum-69-number/solutions/1294083)
    [using stls](https://leetcode.com/problems/maximum-69-number/solutions/484942)

    
TC: O(N)
SC: O(N)

========================================
Day-07, Leetcode November Challenge Study Room Event
*/
// @lc code=end

