/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;     // Negative number always false.
        int tmp = x;
        int last_num = 0;
        long long int y = 0;      // Reversely created number;
        while(tmp > 0){
            last_num = tmp%10;
            tmp/=10;
            y=y*10+last_num;
        }
        return y==x;
    }
};
// @lc code=end

