/* 507. Perfect Number

We define the Perfect Number is a positive integer that is equal to the sum of all its positive 
divisors except itself. Now, given an integer n, write a function that returns true when it is a 
perfect number and false when it is not.

Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
*/

/*这道题让我们判断给定数字是否为完美数字，并给来完美数字的定义，就是一个整数等于除其自身之外的所有的因子之和。
那么由于不能包含自身，所以n必定大于1。其实这道题跟之前的判断质数的题蛮类似的，都是要找因子。由于1肯定是因子，
可以提前加上，那么我们找其他因子的范围是[2, sqrt(n)]。我们遍历这之间所有的数字，如果可以被n整除，那么我们把
i和num/i都加上，对于n如果是平方数的话，那么我们此时相同的因子加来两次，所以我们要减掉一次。还有就是在遍历的过
程中如果累积和sum大于n了，直接返回false即可。在循环结束后，我们看sum是否和num相等*/

class Solution {
public:
    bool checkPerfectNumber(int n) {
        if (n == 1) return false;
        int sum = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) sum += (i + n / i);
            if (i * i == n) sum -= i;
            if (sum > n) return false;
        }
        return sum == n;
    }
};






