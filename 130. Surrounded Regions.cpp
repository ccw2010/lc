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
'O', alter it and all its neighbor 'O' elements to '1'.

2. Then ,alter all the 'O' to 'X'

3. At last,alter all the '1' to 'O'

For example:

         X X X X           X X X X             X X X X
         X X O X  ->       X X O X    ->       X X X X
         X O X X           X 1 X X             X O X X
         X O X X           X 1 X X             X O X X
*/

void solve(vector<vector<char>>& board) {
    int i,j;
    int row=board.size();
    if(!row) return;
    int col=board[0].size();

	for(i=0;i<row;i++){
		check(board,i,0,row,col);
		if(col>1) check(board,i,col-1,row,col);
	}
	for(j=1;j+1<col;j++){
		check(board,0,j,row,col);
		if(row>1) check(board,row-1,j,row,col);
	}
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(board[i][j]=='O')
				board[i][j]='X';
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(board[i][j]=='1')
				board[i][j]='O';
}
void check(vector<vector<char> >&m, int i, int j, int row, int col){
	if(m[i][j]=='O'){
		m[i][j]='1';
		if(i>1) check(m,i-1,j,row,col);
		if(j>1) check(m,i,j-1,row,col);
		if(i+1<row) check(m,i+1,j,row,col);
		if(j+1<col) check(m,i,j+1,row,col);
	}
}





