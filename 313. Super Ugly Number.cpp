/*313. Super Ugly Number
Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime factors are in the given prime list 
primes of size k.

Example:
Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]  is the sequence of the first 12 
             super ugly numbers given primes = [2,7,13,19] of size 4.
Note:
1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.*/

/* Keep k pointers and update them in each iteration. Time complexity is O(kn).
由于我们不知道质数的个数，我们可以用一个idx数组来保存当前的位置，然后我们从每个子链中取出一个数，找出其中最小值，
然后更新idx数组对应位置，注意有可能最小值不止一个，要更新所有最小值的位置*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> dp(n, 1);
        vector<int> idx(k, 0);
        for (int i = 1; i < n; ++i) {
            dp[i] = INT_MAX;
            for (int j = 0; j < k; j++) {
                dp[i] = min(dp[i], dp[idx[j]] * primes[j]);
            }
            for (int j = 0; j < k; j++) {
                if (dp[i] == dp[idx[j]] * primes[j]) {
                    idx[j]++;
                }
            }
        }
        return dp.back();
    }
};













