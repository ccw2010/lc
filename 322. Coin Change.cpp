/* 322. Coin Change 

You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], n = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], n = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
    int coinChange(vector<int> &coins, int num) {
        if (coins.empty()) return 0;
        vector<int> dp(num+1, num+1);
        dp[0] = 0;
        int nCoins = coins.size();
        for (int i = 1; i <= num; i++) {
            for (int j = 0; j < nCoins; j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[num] > num ? -1 : dp[num];
    }
};










