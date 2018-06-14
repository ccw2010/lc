/*
279 Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...)
which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

/*这道题我们可以用动态规划Dynamic Programming来做，我们建立一个长度为n+1的一维dp数组，将第一个值初始化为0，
其余值都初始化为INT_MAX, i从0循环到n，j从1循环到i+j*j <= n的位置，然后每次更新dp[i+j*j]的值，动态更新dp数组，
其中dp[i]表示正整数i能少能由多个完全平方数组成，那么我们求n，就是返回dp[n]即可，也就是dp数组的最后一个数字*/


class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        
        /* dp[i] = the least number of perfect square numbers 
           which sum to i. Note that dp[0] is 0. */
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            /* For each i, it must be the sum of some number (i - j*j) and 
               a perfect square number (j*j). */
            for (int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; i + j*j <= n; j++) {
                dp[i + j*j] = min(dp[i + j*j], dp[i] + 1);
            }
        }
        return dp[n];
    }
};






