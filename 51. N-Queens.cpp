/*51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that 
no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:
Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.*/

/*In this problem, we can go row by row, and in each position, we need to check if the column, 
the 45° diagonal and the 135° diagonal had a queen before.

Solution A: Directly check the validity of each position*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solve(board, res, 0, n);
        return res;
    }

    void solve(vector<string> &board, vector<vector<string>> &res, int row, int &n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(board, res, row + 1, n);
                board[row][col] = '.';
            }
    }
    bool isValid(vector<string> &board, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i=0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;
        
        //check if the 45° diagonal had a queen before.
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;
        
        //check if the 135° diagonal had a queen before.
        for (int i = row-1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;
        
        return true;
    }
};