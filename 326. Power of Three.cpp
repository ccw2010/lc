/*326. Power of Three

Given an integer, write a function to determine if it is a power of three.

Example 1:
Input: 27
Output: true

Example 2:
Input: 0
Output: false

Example 3:
Input: 9
Output: true

Example 4:
Input: 45
Output: false

这道题让我们判断一个数是不是3的次方数，在LeetCode中，有一道类似的题目Power of Two，
那道题有个非常简单的方法，由于2的次方数实在太有特点，最高位为1，其他位均为0，所以特别容易，
而3的次方数没有显著的特点，最直接的方法就是不停地除以3，看最后的余数是否为1，要注意考虑输入
是负数和0的情况 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n && n%3 == 0){
            n /= 3;
        }
        return n == 1;
    }
};
















