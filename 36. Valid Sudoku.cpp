/*36. Valid Sudoku
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the 
following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Three flags are used to check whether a number appear.
used1: check each row
used2: check each column
used3: check each sub-boxes
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return false;
        
        int used1[9][9] = {0};
        int used2[9][9] = {0};
        int used3[9][9] = {0};
        
        int row = board.size(), col = board[0].size();   
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(isdigit(board[i][j])){
                    int num = board[i][j] - '1';
                    int k = 3 * (i / 3) + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num]){
                        return false;
                    }
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
            }
        }
        return true;
    }
};





