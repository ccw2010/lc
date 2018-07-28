/* 264. Ugly Number II

Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:
Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:  
1 is typically treated as an ugly number.
n does not exceed 1690.
*/

/* 这道题是之前那道Ugly Number 丑陋数的延伸，这里让我们找到第n个丑陋数，还好题目中给了很多提示，
基本上相当于告诉我们解法了，根据提示中的信息，我们知道丑陋数序列可以拆分为下面3个子列表：
(1) 1x2, 2x2, 2x2, 3x2, 3x2, 4x2, 5x2...
(2) 1x3, 1x3, 2x3, 2x3, 2x3, 3x3, 3x3...
(3) 1x5, 1x5, 1x5, 1x5, 2x5, 2x5, 2x5...
仔细观察上述三个列表，我们可以发现每个子列表都是一个丑陋数分别乘以2,3,5，而要求的丑陋数就是从已经
生成的序列中取出来的，我们每次都从三个列表中取出当前最小的那个加入序列 */

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(1, 1);
        int i = 0, j = 0, k = 0;
        while (dp.size() < n) {
            int x = dp[i] * 2;
            int y = dp[j] * 3;
            int z = dp[k] * 5;
            int ugly = min(x, min(y, z));
            if (ugly == x) i++;
            if (ugly == y) j++;
            if (ugly == z) k++;
            dp.push_back(ugly);
        }
        return dp.back();
    }
};













