/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=0, buy=INT_MAX, maxP=0;
        for(int i=0; i<prices.size(); ++i){
            sell=prices[i];
            buy=min(buy, prices[i]);
            if((sell-buy) > maxP) maxP=sell-buy;
        }
        return maxP;
    }
};
/*
:
    Find maximum difference

TC: O(N)
SC: O(1)
*/
// @lc code=end

