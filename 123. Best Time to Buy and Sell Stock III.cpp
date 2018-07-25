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


/* Comparing to I and II, III limits the number of transactions to 2. This can be solve by 
"devide and conquer". We use left[i] to track the maximum profit for transactions before i, 
and use right[i] to track the maximum profit for transactions after i. You can use the following 
example to understand the solution:

Prices: 1 4 5 7 6 3 2 9
left = [0, 3, 4, 6, 6, 6, 6, 8]
right= [8, 7, 7, 7, 7, 7, 7, 0]

The maximum profit = 13
*/

class Solution {
public:
    int maxProfit(vector<int> &prices){
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        int minPrice = prices[0];
        for (int i = 1; i < n; i++){
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i-1], prices[i] - minPrice);
        }
        int maxPrice = prices[n-1];
        for (int i = n-2; i > 0; i--){
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(right[i+1], maxPrice - prices[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++){
            res = max(res, left[i] + right[i]);
        }
        return res;
    } 
};








