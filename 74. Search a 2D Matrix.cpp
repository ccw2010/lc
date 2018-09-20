/* 74. Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

/*Use binary search.
n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
an array convert to n * m matrix => a[x] =>matrix[x / m][x % m];
*/

/* 这道题要求搜索一个二维矩阵，由于给的矩阵是有序的，所以很自然的想到要用二分查找法, 
   从矩阵数值的中间点，即左下角开始查找 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int row = matrix.size(), col = matrix[0].size();
        int i = row - 1, j = 0;
        while (i >= 0 && j < col){
            if (target == matrix[i][j]) return true;
            else if (target < matrix[i][j]) i--;
            else if (target > matrix[i][j]) j++;
        }
        return false;
    }
};










