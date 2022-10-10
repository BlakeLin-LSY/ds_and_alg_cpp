/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 */

// @lc code=start
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.length();
        int i=0, j=n-1;
        if(n<=1) return "";     // Edge case, no possible to make it non-palindrome;

        while(i < j && palindrome[i] == 'a'){
            ++i, --j;
        }
        // cout << i << ", " << j << endl;
        if (i == j) i=n-1;        // Change from the end.
        if(i > j) palindrome[i]='b';
        else palindrome[i] = 'a';
        return palindrome;
    }
};
/*

Edge case:
    1. "aa"
    2. "aba"    --> odd, center != 'a'
    3. "aabaa"  --> odd, center != 'a'  --> need to start from the end.

TC: O(N)
SC: O(1)
*/

// @lc code=end

