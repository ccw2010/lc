/*123. Best Time to Buy and Sell Stock III

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/


/*这道是买股票系列中最难最复杂的一道，前面121,122的思路都非常的简洁明了，算法也很简单。而这道是要求最多交易两次，
找到最大利润，还是需要用动态规划Dynamic Programming来解，而这里我们需要两个递推公式来分别更新两个变量local和global，
我们其实可以求至少k次交易的最大利润，找到通解后可以设定 k = 2，即为本题的解答。

我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。
然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：

local[i][j]  = max(global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff)
global[i][j] = max(local[i][j], global[i-1][j])

其中局部最优值是比较前一天并少交易一次的全局最优加上大于0的差值，和前一天的局部最优加上差值中取较大值，
而全局最优比较局部最优和前一天的全局最优 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        int g[n][3] = {0};
        int l[n][3] = {0};
        int k = 2;
        for (int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i-1];
            for (int j = 1; j <= k; j++) {
                l[i][j] = max(g[i-1][j-1] + max(diff, 0), l[i-1][j] + diff);
                g[i][j] = max(l[i][j], g[i-1][j]);
            }
        }
        return g[n-1][2];
    }
};






