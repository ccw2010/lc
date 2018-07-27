/* 233. Number of Digit One

Given an integer n, count the total number of digit 1 appearing in all non-negative integers 
less than or equal to n.

Example:
Input: 13
Output: 6 
Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/


/* The idea is check number of 1 for each 10,100,1000,10000 ... position. For example, for 312:

check 000~099, 100~199, 200~299, 300~312 and sum them up, for 000~099 and 200~299, it's countDigitOne(99), 
for 100~199 it's 100+countDigitOne(99), and for 300~312 it's countDigitOne(12).*/

class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1) return 0;
        if (n >= 1 && n < 10) return 1;
        /* x: first digit */
        int y = 1, x = n;
        while (x >= 10){
            x /= 10;
            y *= 10;
        }
        if (x == 1) return n - y + 1 + countDigitOne(y-1) + countDigitOne(n%y);
        else return y + x * countDigitOne(y-1) + countDigitOne(n%y);
    }
};














