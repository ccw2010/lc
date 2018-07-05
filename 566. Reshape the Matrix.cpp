/*
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into 
a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c 
representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same 
row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; 
Otherwise, output the original matrix.

Example 1:
Input: 
nums = [ [1,2],
         [3,4] ]
r = 1, c = 4
Output: 
[[1,2,3,4]]

Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row 
by using the previous list.

Example 2:
Input: 
nums = [ [1,2],
         [3,4] ]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]] 

Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
*/

/*这道题让我们实现矩阵大小的重塑，对于这种二维数组大小重新非配的问题的关键就是对应位置的坐标转换，最直接的办法就是先把
原数组拉直，变成一条直线，然后再组成新的数组。所以这道题我们先判断给定数组是否能重塑成给定的大小，就是看两者的元素总数
是否相同，直接行数乘以列数即可，然后我们新建一个目标大小的数组，并开始遍历，对于每个位置，我们先转为拉直后的一维坐标，
然后在算出在原数组中的对应位置赋值过来即可*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int col = nums[0].size();
        if (row*col != r * c) return nums;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r * c; i++) {
            res[i/c][i%c] = nums[i/col][i%col];
        }
        return res;
    }
};



