/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> vals;
        char sign=' ';
        for(auto &token:tokens){
            for(int i=0; i<token.size(); ++i){
                char c=token[i];
                if(c>='0'){
                    int number=0;
                    while(i<token.size() && token[i]>='0') number=10*number+(token[i++]-'0');
                    if(sign=='-') number=0-number;
                    vals.push_back(number);
                    sign=' ';
                }else{
                    sign=c;
                }

                if(sign!=' ' && token.size()==1){
                    int buf=vals.back();
                    vals.pop_back();
                    long newVal=vals.back();
                    vals.pop_back();
                    if(sign=='+') newVal+=buf;
                    else if(sign=='-') newVal-=buf;
                    else if(sign=='*') newVal*=buf;
                    else if(sign=='/') newVal/=buf;
                    vals.push_back(newVal);
                    sign=' ';
                }
            }
            // for(auto &v:vals) cout << v << " ";
            // cout << endl;
        }
        return vals.back();
    }
};
/*
:
    Reversed Polish Notation -> keep values and signs in stack, clear signs every encounter

# Idea:
    ## 1st
        store values in stack, every time encounter sign, compute the value

    ### Key Points:
      1. Edge case "negative number" --> character in front 
        ["-1","1","*","-1","+"]
      2. Large number
        ["-128","-128","*","-128","*","-128","*","8","*","-1","*"]

    ### Any Improvement Ideas / Related Questions:
      - 
      
00:06:  Read problem
00:25:  1st implementation
00:47:  Modify (2nd implemntation) -> input is vector<string>, +debug
01:19:  Passed (modify and debug) 1. negative number, 2. large number

# Note:

22/22 cases passed (7 ms)
Your runtime beats 98.04 % of cpp submissions
Your memory usage beats 99.63 % of cpp submissions (11.7 MB)

TC: O(N)
SC: O(k) -> k is the number of values

========================================
2022-Dec Day-17, Leetcode November Challenge Study Room Event
*/
// @lc code=end

