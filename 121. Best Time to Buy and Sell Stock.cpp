/*121. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
 design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.*/

/*这道题让我们求买卖股票的最大利润，限制条件是只能进行一次买和卖的操作。这道题只需要遍历一次数组，
用一个变量记录遍历过数中的最小值，然后每次计算当前值和这个最小值之间的差值最为利润，然后每次选较大的利润来更新。
当遍历完成后当前利润即为所求 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int cost = INT_MAX;
        for (int price : prices) {
            cost = min(cost, price);
            res = max(res, price - cost);
        }
        return res;
    }
};






