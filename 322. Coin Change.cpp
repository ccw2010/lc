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


/*这道题给我们了一些可用的硬币值，又给了一个钱数，问我们最小能用几个硬币来找零。根据题目中的例子可知，不是每次都会
给全1,2,5的硬币，有时候没有1分硬币，那么有的钱数就没法找零，需要返回-1。这道题跟CareerCup上的 9.8 Represent 
N Cents 美分的组成有些类似，那道题给全了所有的美分，25,10,5,1，然后给我们一个钱数，问我们所有能够找零的方法，
而这道题只让我们求出最小的那种，对于求极值问题，我们还是主要考虑动态规划Dynamic Programming来做，我们维护一个
一维动态数组dp，其中dp[i]表示钱数为i时的最小硬币数的找零，递推式为：

dp[i] = min(dp[i], dp[i - coins[j]] + 1);

其中coins[j]为第j个硬币，而i - coins[j]为钱数i减去其中一个硬币的值，剩余的钱数在dp数组中找到值，然后加1和当前
dp数组中的值做比较，取较小的那个更新dp数组 */



class Solution {
public:
    int coinChange(vector<int> &coins, int num) {
        if (coins.empty()) return 0;
        vector<int> dp(num + 1, INT_MAX);
        dp[0] = 0;
        int nCoins = coins.size();
        for (int i = 1; i <= num; i++) {
            for (int j = 0; j < nCoins; j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if (dp[num] > num) return -1;
        else return dp[num];
    }
};










