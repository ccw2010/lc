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

/*这道题让我们验证一个方阵是否为数独矩阵，判断标准是看各行各列是否有重复数字，以及每个小的3x3的小方阵里面是否有重复数字，
如果都无重复，则当前矩阵是数独矩阵，但不代表待数独矩阵有解，只是单纯的判断当前未填完的矩阵是否是数独矩阵。那么根据数独矩
阵的定义，我们在遍历每个数字的时候，就看看包含当前位置的行和列以及3x3小方阵中是否已经出现该数字，那么我们需要三个标志矩阵，
分别记录各行，各列，各小方阵是否出现某个数字，其中行和列标志下标很好对应，就是小方阵的下标需要稍稍转换一下*/


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





