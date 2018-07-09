/* 693. Binary Number with Alternating Bits
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits 
will always have different values.

Example 1:
Input: 5
Output: True
Explanation: The binary representation of 5 is: 101

Example 2:
Input: 7
Output: False
Explanation: The binary representation of 7 is: 111.

Example 3:
Input: 11
Output: False
Explanation: The binary representation of 11 is: 1011.

Example 4:
Input: 10
Output: True
Explanation: The binary representation of 10 is: 1010.*/

/*利用了0和1的交替的特性，进行错位相加，从而组成全1的二进制数，然后再用一个检测全1的二进制数的trick，
就是‘与’上加1后的数，因为全1的二进制数加1，就会进一位，并且除了最高位，其余位都是0，跟原数相‘与’就会得0，
所以可以这样判断。比如n是10101，那么n>>1就是1010，二者相加就是11111，再加1就是100000，二者相‘与’就是0*/


class Solution {
public:
    bool hasAlternatingBits(int n) {
        int allOne = n + (n >> 1);
        int allZero = allOne + 1;
        return (allZero & allOne) == 0;
    }
};












