/*348. Design Tic-Tac-Toe

Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|

Follow up:
Could you do better than O(n2) per move() operation? */

/*我们首先来O(n^2)的解法，这种方法的思路很straight forward，就是建立一个nxn大小的board，其中0表示该位置
没有棋子，1表示玩家1放的子，2表示玩家2。那么棋盘上每增加一个子，我们都扫描当前行列，对角线，和逆对角线，看看
是否有三子相连的情况，有的话则返回对应的玩家，没有则返回0*/

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
         board.resize(n, vector<int>(n, 0)); 
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        int i = 0, j = 0;
        int n = board.size();
        /* check each row */
        for (j = 1; j < n; j++) {
            if (board[row][j] != board[row][j-1]) break;
        }
        if (j == n) return player;
		/* check each colomn */
        for (i = 1; i < n; i++) {
            if (board[i][col] != board[i-1][col]) break;
        }
        if (i == n) return player;
        /* check diagonal 1*/
        if (row == col) {
            for (i = 1; i < n; i++) {
                if (board[i][i] != board[i-1][i-1]) break;
            }
            if (i == n) return player;
        }
        /* check diagonal 2*/
        if (row + col == n-1) {
            for (i = 1; i < n; i++) {
                if (board[n-i-1][i] != board[n-i][i-1]) break;
            }
            if (i == n) return player;
        }
        return 0;
    }
private:
    vector<vector<int>> board;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */


/*Follow up中让我们用更高效的方法，那么根据提示中的，我们建立一个大小为n的一维数组rowDiff和colDiff，还有变量对角线diag1
和逆对角线diag2，这种方法的思路是，如果玩家1在第一行某一列放了一个子，那么rowDiff[0]自增1，如果玩家2在第一行某一列放了一个子，
则rowDiff[0]自减1，那么只有当rowDiff[0]等于n或者-n的时候，表示第一行的子都是一个玩家放的，则游戏结束返回该玩家即可，其他各行
各列，对角线和逆对角线都是这种思路*/

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
       : rowDiff_(n,0), colDiff_(n,0)
       , n_(n), diag1_(0), diag2_(0) {
    }

    int move(int i, int j, int player) {
        int add;
        if (player==1) add = 1;
        else add = -1;
        rowDiff_[i] += add; 
        colDiff_[j] += add;
        if (i==j) diag1_ += add;
        if (i == n_-j-1) diag2_ += add;
        
        if (abs(rowDiff_[i]) == n_ || abs(colDiff_[j]) == n_ || abs(diag1_) == n_ || abs(diag2_) == n_){
            return player;
        } else return 0;
    }

private:
    vector<int> rowDiff_, colDiff_;
    int diag1_, diag2_, n_;
};





