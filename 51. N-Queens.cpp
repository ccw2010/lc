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

/*经典的N皇后问题，解法为回溯递归，一层一层的向下扫描，需要用到一个pos数组，其中pos[i]表示第i行皇后的位置，
初始化为-1，然后从第0开始递归，每一行都一次遍历各列，判断如果在该位置放置皇后会不会有冲突，以此类推，当到最后
一行的皇后放好后，一种解法就生成了，将其存入结果res中，然后再还会继续完成搜索所有的情况*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> pos(n, -1);
        solve(pos, 0, res);
        return res;
    }
    void solve(vector<int> &pos, int row, vector<vector<string>> &res) {
        int n = pos.size();
        if (row == n) {
            vector<string> solution(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                solution[i][pos[i]] = 'Q';
            }
            res.push_back(solution);
        } else {
            for (int col = 0; col < n; ++col) {
                if (isValid(pos, row ,col)) {
                    pos[row] = col;
                    solve(pos, row + 1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    bool isValid(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
};


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
        for (int i=0; i < row; i++){
            if (board[i][col] == 'Q') return false;
        }
        
        //check if the 45° diagonal had a queen before.
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if (board[i][j] == 'Q') return false;
        }
        
        //check if the 135° diagonal had a queen before.
        for (int i = row-1, j = col + 1; i >= 0 && j < n; i--, j++){
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
};










