/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
class Solution
{
public:
    int dp[101][101][101];
    int M = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int m = group.size();
        group.insert(group.begin(), 0);
        profit.insert(profit.begin(), 0);
        dp[0][0][0] = 1;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                for (int p = 0; p <= minProfit; ++p)
                {
                    // Not execute any project
                    dp[i + 1][j][p] += dp[i][j][p];
                    dp[i + 1][j][p] %= M;

                    if (j + group[i + 1] <= n)
                    {
                        dp[i + 1][j + group[i + 1]][min(minProfit, p + profit[i + 1])] += dp[i][j][p];
                        dp[i + 1][j + group[i + 1]][min(minProfit, p + profit[i + 1])] %= M;
                    }
                }
            }
        }
        int res = 0;
        for (int j = 0; j <= n; ++j)
            res = (res + dp[m][j][minProfit]) % M;
        return res;
    }
};
/*
DP

profit -> can only be choose once
group -> cost group[i] people to to
n -> total people
minProfit -> profit scheme must >= minProfit

00:12:  Can't figure out dp statement, check video
    https://youtu.be/SGod9bCXYfw



# Key notes
    考慮第i個項目（人力是x，利潤是y）
        dp[i][person][profit] = dp[i-1][person][profit] + dp[i-1][person-x][profit-y]

    假設已知dp[i][person][profit]，那麼我們可以推測對i+1的影響
        dp[i+1][j][p] += dp[i][j][p];
        dp[i+1][j+group[i+1]][min(minProfit, p+profit[i+1])] += dp[i][j][p];


45/45 cases passed (207 ms)
Your runtime beats 50.92 % of cpp submissions
Your memory usage beats 50 % of cpp submissions (12.9 MB)

TC: O(n^3)  -> n<=100
SC: O(n^3)
*/
// @lc code=end
