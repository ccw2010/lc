/* 461. Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding 
bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

/*这道题让我求两个数字之间的汉明距离，两个数字之间的汉明距离就是其二进制数对应位不同的个数，
那么最直接了当的做法就是按位分别取出两个数对应位上的数并异或，我们知道异或的性质上相同的为0，
不同的为1，我们只要把为1的情况累加起来就是汉明距离了. 我们可以一开始直接将两个数字异或起来，
然后我们遍历异或结果的每一位，统计为1的个数*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int b = 1 << i;
            if ((x & b) ^ (y & b)) {
                res++;
            }
        }
        return res;
    }
};

/*我们可以对上面的代码进行优化，一开始直接将两个数字异或起来，然后遍历异或结果的每一位，统计为1的个数。
假如异或的结果为exc, exc & (exc - 1)可以快速地移除最右边的bit 1， 一直循环到exc为0, 总的循环数就是
exc中bit 1的个数。*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, exc = x ^ y;
        while (exc) {
            res++;
            exc &= (exc - 1);
        }
        return res;
    }
};








