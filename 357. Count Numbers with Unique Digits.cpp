/*
357. Count Numbers with Unique Digits
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 
[11,22,33,44,55,66,77,88,99]) 

when n is 0, it is clear that there is just one number 0.

when n is 1, it is trivial that there are 10 numbers: 0,1,2...9.

when n is 2, the range is [0, 99]. The total unique digits is divided to two part: just one digit or two digit.

dp[2]  = dp[1] + the combination with  two digits.

'0' could only be at unit digit. so when '0' is at unit digit, there are 9 kinds of. when there is no '0', there 
are 9 kinds of numbers at tens digit, and 8 kinds of numbers at unit digit. So the combination with two digits 
are: 9 + 9 * 8 is equal to

9 * (1+8) = 9 * 9.

when n is 3, the range is [0, 999]. The total unique digits is divided to two part: less than 3 digit or 3 digit.

dp[3]  = dp[2] + the combination with  3 digits.

'0' could only be at unit digit and ten's digit.

When '0' is at unit digit, there are 9 * 8 kind of numbers(9 is the kind of numbers at hundred's digit, 8 is 
the kind of numbers at ten's digit);

When '0' is at ten's digit, there are 9 * 8 kind of numbers(9 is the kind of numbers at hundred's digit, 8 is 
the kind of numbers at unit digit);

When there is no '0', there are 9 * 8 * 7 kinds of numbers(9 is the kind of numbers at hundred's digit, 8 is 
the kind of numbers at ten's digit, 7 is the kind of numbers at unit digit).

So there are: 

9 * 8  + 9 * 8 + 9 * 8 * 7  = 9 * 8 * (1 + 1 + 8 ) = 9 * 9 * 8 

kinds of combinations with three digits.

Than it is easy to understand the DP solution of this problem.
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1);
        dp[0] = 1; dp[1] = 10;
        for(int i=2; i<=n; i++){
            dp[i] = 9;
            for(int j=1, k=9; j<i; j++, k--){
                dp[i] = dp[i] * k;
            }
            dp[i] += dp[i-1];
        }
        return dp[n];   
    }
};





