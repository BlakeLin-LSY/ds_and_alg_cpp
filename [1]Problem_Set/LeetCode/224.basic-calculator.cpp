/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int total = 0;
        vector<int> signs(2, 1);
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            if (c >= '0') {
                int number = 0;
                while (i < s.size()  &&  s[i] >= '0')
                    number = 10 * number + (s[i++] - '0');
                total += signs.back() * number;
                signs.pop_back();
                i--;
            }
            else if(c=='(' and s[i+1]=='-'){}
            else if (c == ')')
                signs.pop_back();
            else if (c != ' ')
                signs.push_back(signs.back() * (c == '-' ? -1 : 1));
        }
        return total;
    }
};
/*
# Note:
    https://leetcode.com/problems/basic-calculator/solutions/62344/
    https://labuladong.github.io/algo/4/33/127/

# Edge case:
    "2147483647"
    >>
        number = 10 * number + (s[i++] - '0');

    "-(-2)+4"
    >>
        else if(c=='(' and s[i+1]=='-'){}

TC: O()
SC: O()

========================================
Day-0x, Leetcode November Challenge Study Room Event
*/
// @lc code=end

