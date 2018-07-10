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

/*这道题要求搜索一个二维矩阵，由于给的矩阵是有序的，所以很自然的想到要用二分查找法，如果我们按S型遍历该二维数组，
可以得到一个有序的一维数组，那么我们只需要用一次二分查找法，而关键就在于坐标的转换，如何把二维坐标和一维坐标转换
是关键点，把一个长度为n的一维数组转化为m*n的二维数组(m*n = n)后，那么原一维数组中下标为i的元素将出现在二维数组
中的[i/n][i%n]的位置，有了这一点*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &m, int k) {
        if(m.empty() || m[0].empty()) return false;
        int row = m.size();
        int col = m[0].size();
        int left = 0, right = row * col - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (m[mid/col][mid%col] < k) left = mid + 1;
            else right = mid;
        }
        return m[left/col][left%col] == k;
    }
};











