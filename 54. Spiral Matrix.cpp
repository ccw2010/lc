/*54. Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int h = matrix.size(), w = matrix[0].size();
        vector<int> res(w*h, 0);
        int top = 0, bottom = h - 1;
        int left = 0, right = w - 1;
        int k = 0;
        while (top<=bottom && left <= right) {
            // up
            for (int j = left; j <= right; j++) {
                res[k++] = matrix[top][j];
            }
            top++;

            // right
            for (int i = top; i <= bottom; i++) {
                res[k++] = matrix[i][right];
            }
            right--;
    
            // down
            for (int j = right; j >= left; j--) {
                res[k++] = matrix[bottom][j];
            }
            bottom--;

            // left
            for (int i = bottom; i >= top; i--) {
                res[k++] = matrix[i][left];
            }
            left++;
        }
        return res;
    }
};









