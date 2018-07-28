/*240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the 
following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Consider the following matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Example 1:
Input: matrix, target = 5
Output: true

Example 2:
Input: matrix, target = 20
Output: false
*/

/*我们观察题目中给的那个例子，我们可以发现有两个位置的数字很有特点，左下角和右上角的数。左下角的18，往上所有的数变小，
往右所有数增加，那么我们就可以和目标数相比较，如果目标数大，就往右搜，如果目标数小，就往左搜。这样就可以判断目标数是
否存在。当然我们也可以把起始数放在右上角，往左和下搜，停止条件设置正确就行。*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int k) {
        if (m.empty() || m[0].empty()) return false;
        if (k < m[0][0] || k > m.back().back()) return false;
        int r = m.size() - 1, c = 0;
        while (r >= 0 && c < m[0].size()) {
            if (m[r][c] > k) r--;
            else if (m[r][c] < k) c++;
            else return true;
        }
        return false;
    }
};








