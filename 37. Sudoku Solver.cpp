/* Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Empty cells are indicated by the character '.'.

SOLUTION: Try 1 through 9 for each cell. The time complexity should be 9 ^ m (m represents the number of blanks 
to be filled in), since each blank can have 9 choices. Details see comments inside code.*/

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        if(board.empty() || board[0].empty()) return;
        solve(board);
    }
    
    bool solve(vector<vector<char>> &board){
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(isdigit(board[i][j])) continue;
                for(char c = '1'; c <= '9'; c++){      // Try 1 through 9
                    if(isvalid(board, i, j, c)){
                        board[i][j] = c;               // Put c for this cell
                        if(solve(board)) return true;  // If it's the solution return true
                        else board[i][j] = '.';        // Otherwise go back
                    }
                }          
                return false;
            }
        }
        return true;
    }
    
    bool isvalid(vector<vector<char>> &board, int row, int col, char c){
        for(int i = 0; i < 9; i++) {
            int x = 3 * (row / 3) + i / 3;
            int y = 3 * (col / 3) + i % 3;
            if(isdigit(board[i][col]) && board[i][col] == c) return false;  // check row
            if(isdigit(board[row][i]) && board[row][i] == c) return false;  // check column
            if(isdigit(board[x][y])   && board[x][y] == c)   return false;  // check 3*3 block
        }
        return true;
    }
};















