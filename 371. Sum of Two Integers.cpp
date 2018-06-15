/*371. Sum of Two Integers

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3. 
*/

/*直接进行异或操作
a ^ b         直接算出 a + b 不带进位的和， 
(a & b) << 1  得到进位（只有两个位均为1才会进位嘛，左移表示进到下一位啊）
用异或算不带进位的和，用与并左移1位来算进位，然后把两者加起来即可，递归的写法如下*/

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        int sum = a ^ b;
        int carry = (a & b) << 1;
        return getSum(sum, carry);
    }
};


/* 也可以写成迭代的样子，思路都是一样的 */

class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while (b) {
            carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};




