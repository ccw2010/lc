/*231. Power of Two

Given an integer, write a function to determine if it is a power of two.

Example 1:
Input: 1
Output: true

Example 2:
Input: 16
Output: true

Example 3:
Input: 218
Output: false
*/

/*
这道题让我们判断一个数是否为2的次方数，而且要求时间和空间复杂度都为常数，那么对于这种玩数字的题，
我们应该首先考虑位操作 Bit Operation。在LeetCode中，位操作的题有很多，比如比如 Repeated DNA Sequences，
Single Number,  Single Number II， Grey Code， Reverse Bits，Bitwise AND of Numbers Range，
Number of 1 Bits 和 Divide Two Integers 等等。那么我们来观察下2的次方数的二进制写法的特点：

1    2      4      8       16 　　....
1    10    100    1000    10000　....

那么我们很容易看出来2的次方数都只有一个1，剩下的都是0，所以我们的解题思路就有了，我们只要每次判断最低位是否为1，
然后向右移位，最后统计1的个数即可判断是否是2的次方数 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count == 1;
    }
};





