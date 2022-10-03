/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Since it is unsigned
        uint32_t ans=0;
        for(int i=0; i<31; ++i){
            if(n & 1) ans += 1;
            ans <<= 1;
            n >>= 1;
        }
        return ans + (n & 1);   // Note the last digit
    }
};
// @lc code=end

