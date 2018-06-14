52. N-Queens II
DescriptionHintsSubmissionsDiscussSolution

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

/*这道题是51.N-Queens的延伸，上一道题比这道题还要稍稍复杂一些，两者本质上没有啥区别，都是要用回溯法Backtracking来解，
此题在51.N-Queens上只要做很小的改动即可，不再需要求出具体的皇后的摆法，只需要每次生成一种解法时，计数器加一即可 */

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        dfs(pos, 0, res);
        return res;
    }
    void dfs(vector<int> &pos, int row, int &res) {
        int n = pos.size();
        if (row == n) {
            res++;
        } else {
            for (int col = 0; col < n; ++col) {
                if (valid(pos, row, col)) {
                    pos[row] = col;
                    dfs(pos, row + 1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    bool valid(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row-i) == abs(col - pos[i])) {
                return false;
            }
        }
        return true;
    }
};





