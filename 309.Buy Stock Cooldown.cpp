/* 309. Best Time to Buy and Sell Stock with Cooldown

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you
buy again). After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]

*/


/*The series of problems are typical dp. The key for dp is to find the variables to represent the states 
and deduce the transition function.

Of course one may come up with a O(1) space solution directly, but I think it is better to be generous 
when you think and be greedy when you implement.

The natural states for this problem is the 3 possible transactions : buy, sell, rest. 
Here cooldown means no transaction on that day.

Then the transaction sequences can end with any of these three states.

For each of them we make an array, buy[n], sell[n] and cooldown[n].

buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。

sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。

cooldown[i]表示在第i天之前最后一个操作是冷冻期，此时的最大收益。

我们写出递推式为：

buy[i]  = max(rest[i-1] - price, buy[i-1]) 
sell[i] = max(buy[i-1] + price, sell[i-1])
rest[i] = max(sell[i-1], buy[i-1], cooldown[i-1])

上述递推式很好的表示了在买之前有冷冻期，买之前要卖掉之前的股票。一个小技巧是如何保证[buy, rest, buy]的情况不会出现，
这是由于buy[i] <= rest[i]， 即rest[i] = max(sell[i-1], rest[i-1])，这保证了[buy, rest, buy]不会出现。

另外，由于冷冻期的存在，我们可以得出rest[i] = sell[i-1]，这样，我们可以将上面三个递推式精简到两个：

buy[i]  = max(sell[i-2] - price, buy[i-1]) 
sell[i] = max(buy[i-1] + price, sell[i-1])
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int n = prices.size();
        int buy[n+1] = {0};
        int sell[n+1] = {0};
        int cooldown[n+1] = {0};
        buy[0] = -prices[0];
        for(int i=1; i<n; i++){
            buy[i] = max(buy[i-1], cooldown[i-1]-prices[i]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
            cooldown[i] = max(cooldown[i-1], sell[i-1]);                       
        }
        return sell[n-1];
    }
};









