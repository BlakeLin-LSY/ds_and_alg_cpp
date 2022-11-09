/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(char &c:s) ++freq[c];

        bool isEven=false;
        int ans=0;
        for(auto [ch, count]:freq){
            ans+=count;
            if(count%2) {
                isEven=true;
                --ans;
            }
        }
        return isEven ? ans+1:ans;
    }
};
/*
:
    longest palindrome, with input string (can be reordered)

# Idea:
    1. Count the frequency
    2. Add up all the even numbers
    3. a bool to check to be even (with any count %2==1)
    4. Return the add up sum of length

# Note:
    Lower and upper characters

TC: O(N)
SC: O(N)    --> O(52)
*/
// @lc code=end

