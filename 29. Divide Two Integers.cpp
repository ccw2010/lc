/*29. Divide Two Integers

Given two integers dividend and divisor, divide two integers without using multiplication, 
division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3

Example 2:
Input: dividend = 7, divisor = -3
Output: -2

Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed i
nteger range: [−2^31, 2^31 −1]. For the purpose of this problem, assume that your function returns 2^31 −1 
when the division result overflows.
*/

/*这道题让我们求两数相除，而且规定我们不能用乘法，除法和取余操作，那么我们还可以用另一神器位操作Bit Operation，
思路是，如果被除数大于或等于除数，则进行如下循环，定义变量t等于除数，定义计数p，当t的两倍小于等于被除数时，进行
如下循环，t扩大一倍，p扩大一倍，然后更新res和m。这道题的OJ给的一些test case非常的讨厌，因为输入的都是int型，
比如被除数是-2147483648，在int范围内，当除数是-1时，结果就超出了int范围，需要返回INT_MAX，对于这种情况我们
就在开始用if判定，将其和除数为0的情况放一起判定，返回INT_MAX。然后我们还要根据被除数和除数的正负来确定返回值的
正负，这里我们采用长整型long来完成所有的计算，最后返回值乘以符号即可*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign;
        if ((dividend < 0) ^ (divisor < 0)) {
            sign = -1;
        } else {
            sign = 1;
        }

        long dvd = abs((long)dividend);
        long dvs = abs((long)divisor);
        if (dvd < dvs) return 0;  
        
        long res = 0;
        while (dvd >= dvs) {
            long  t = dvs, p = 1;
            while (dvd > (t << 1)) {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            dvd -= t;
        }
        res = sign * res;
        return (int) min( (long)INT_MAX, res);
    }
};






