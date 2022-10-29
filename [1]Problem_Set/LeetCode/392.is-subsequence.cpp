/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size()) return false;
        int i=0, j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                ++i;
            }
            ++j;
        }
        return i==s.size();
    }
};
/*
:
    subsequence check;
        definition:
            1. with order
            2. can have gap in between

# Idea
    1. Brute force (go through s to check one by one) --> since have order

    # Edge cases:
        - s=""                  // empty string is a subsequence? --> true
        - s="b", t="c"          // s & t are both one character

    # Any follow-up (speed-up method?)
        - Currently TC=O(N)
        - (trivial) check s.size() < t.size() at the begining
        - O(N) should be enough

    # Other's solution
    [2pointers, binary search](https://leetcode.com/problems/is-subsequence/solutions/707793/c-2-solutions-two-pointer-and-binary-search/?envType=study-plan&id=level-1&orderBy=most_votes&languageTags=cpp)
    [recursive, 2pointers, dp](https://leetcode.com/problems/is-subsequence/solutions/678426/c-3-approaches-1-recursion-2-two-pointer-3-dynamic-programming/)

TC: O(N)
SC: O(1)

Tags:
    string, two pointer, binary search;
*/
// @lc code=end

