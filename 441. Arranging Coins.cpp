/*441. Arranging Coins

You have a total of n coins that you want to form in a staircase shape, where every k-th 
row must have exactly k coins.
Given n, find the total number of full staircase rows that can be formed.
n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:
n = 5
The coins can form the following rows:
¤
¤ ¤
¤ ¤
Because the 3rd row is incomplete, we return 2.


Example 2:
n = 8
The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤
Because the 4th row is incomplete, we return 3.*/


/*这道题给了我们n个硬币，让我们按一定规律排列，第一行放1个，第二行放2个，以此类推，问我们有多少行能放满。
通过分析题目中的例子可以得知最后一行只有两种情况，放满和没放满。由于是按等差数列排放的，我们可以快速计算出前i行的
硬币总数。我们先来看一种O(n)的方法，非常简单粗暴，就是从第一行开始，一行一行的从n中减去，如果此时剩余的硬币没法
满足下一行需要的硬币数了，我们之间返回当前行数即可
*/


class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0) return 0;
        int row = 1;
        n--;
        while (n >= row + 1) {
            ++row;
            n -= row;
        }
        return row;
    }
};








