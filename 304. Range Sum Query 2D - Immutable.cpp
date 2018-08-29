/*304. Range Sum Query 2D - Immutable 二维区域和检索 - 不可变
 
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner 
(row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which 
contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12

Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
 

这道题让我们求一个二维区域和的检索，是303.Range Sum Query - Immutable 的延伸。有了之前那道题的基础，我们知道此题
还是要建立一个累计区域和的数组，然后根据边界值的加减法来快速求出给定区域之和。这里我们维护一个二维数组dp，其中dp[i][j]
表示累计区间(0, 0)到(i, j)这个矩形区间所有的数字之和，那么此时如果我们想要快速求出(r1, c1)到(r2, c2)的矩形区间时，
只需dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1]即可，下面的代码中由于用了辅助列和辅助行，所以
下标会有些变化 

Given matrix = {
   {3, 0, 1, 4, 2},
   {5, 6, 3, 2, 1},
   {1, 2, 0, 1, 5},
   {4, 1, 0, 1, 7},
   {1, 0, 3, 0, 5}
};

dp = {
  {3, 3, 4, 8, 10},
  {8, 14, 18, 24, 27},
  {9, 17, 21, 28, 36},
  {13, 22, 26, 34, 49},
  {14, 23, 30, 38, 58}
}


sumRegion(2, 1, 4, 3) -> dp[4][3] - dp[1][3] - dp[4][0] + dp[1][0] = 38 - 24 - 14 + 8 = 8
sumRegion(1, 1, 2, 2) -> dp[2][2] - dp[0][2] - dp[2][0] + dp[0][0] = 21 - 4  -  9 + 3 = 11
sumRegion(1, 2, 2, 4) -> dp[2][4] - dp[0][4] - dp[2][1] + dp[0][1] = 36 - 10 - 17 + 3 = 12

*/


class NumMatrix {
private:
    vector<vector<int>> dp;
 
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int row = matrix.size();
        int col = matrix[0].size();
        dp = matrix;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = matrix[0][0];
                } else if (i == 0){
                    dp[i][j] = dp[i][j-1] + matrix[i][j];
                } else if (j == 0){
                    dp[i][j] = dp[i-1][j] + matrix[i][j];
                } else{
                    dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + matrix[i][j];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        if (row1 == 0 && col1 == 0) res = dp[row2][col2];
        else if (row1 == 0) res = dp[row2][col2] - dp[row2][col1-1];
        else if (col1 == 0) res = dp[row2][col2] - dp[row1-1][col2];
        else res = dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1] + dp[row1-1][col1-1];
        return res;
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */










