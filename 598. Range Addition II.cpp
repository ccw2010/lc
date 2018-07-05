/*598. Range Addition II
Given an m * n matrix M initialized with all 0's and several update operations.
Operations are represented by a 2D array, and each operation is represented by an array with two 
positive integers a and b, which means M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.
You need to count and return the number of maximum integers in the matrix after performing all the operations.

Example 1:
Input: 
m = 3, n = 3
operations = [[2,2],[3,3]]
Output: 4
Explanation: 
Initially, M = 
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]

After performing [2,2], M = 
[[1, 1, 0],
 [1, 1, 0],
 [0, 0, 0]]

After performing [3,3], M = 
[[2, 2, 1],
 [2, 2, 1],
 [1, 1, 1]]

So the maximum integer in M is 2, and there are four of it in M. So return 4.*/

/*每次在ops中给定我们一个横纵坐标，将这个子矩形范围内的数字全部自增1，让我们求最大数字的个数。
原数组初始化均为0，那么如果ops为空，没有任何操作，那么直接返回m*n即可，通过举例发现，只有最小
数字组成的边界中的数字才会被每次更新，所以每次用ops中的值来更新m和n，取其中较小值，这样遍历完
成后，m和n就是最大数矩阵的边界了*/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto op : ops){
            m = min(m, op[0]);
            n = min(n, op[1]);
        }
        return m * n;
    }
};











