/*130. Surrounded Regions

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X

Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are 
not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border 
will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or 
vertically.
*/


/*
1. First, check the four border of the matrix. If there is a element is
'O', alter it and all its neighbor 'O' elements to '$'.

2. Then ,alter all the 'O' to 'X'

3. At last,alter all the '$' to 'O'

For example:

         X X X X           X X X X             X X X X
         X X O X  ->       X X O X    ->       X X X X
         X O X X           X $ X X             X O X X
         X O X X           X $ X X             X O X X
*/

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int row = board.size();
        if (row == 0) return;
        int col = board[0].size();

        for (int i=0; i<row; i++){
            dfs(board, i, 0);
            if (col>1) dfs(board, i, col-1);
        }
        for (int j=1; j+1<col; j++){
            dfs(board, 0, j);
            if (row > 1) dfs(board, row-1, j);
        }
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>> &board, int i, int j){
        int row = board.size(), col = board[0].size();
        if (board[i][j] == 'O'){
            board[i][j] = '$';
            if (i > 1) dfs(board, i-1, j);
            if (j > 1) dfs(board, i, j-1);
            if (i+1 < row) dfs(board, i+1, j);
            if (j+1 < col) dfs(board, i, j+1);
        }
    }
};





