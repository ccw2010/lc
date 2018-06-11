/*764. Largest Plus Sign

In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given 
list mines which are 0. What is the largest axis-aligned plus sign of 1s contained in the grid? 
Return the order of the plus sign. If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of 
length k-1 going up, down, left, and right, and made of 1s. This is demonstrated in the diagrams 
below. Note that there could be 0s or 1s beyond the arms of the plus sign, only the relevant area 
of the plus sign is checked for 1s.

Examples of Axis-Aligned Plus Signs of Order k:

Order 1:
000
010
000

Order 2:
00000
00100
01110
00100
00000

Order 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000

Example 1:
Input: N = 5, mines = [[4, 2]]
Output: 2
Explanation:
11111
11111
11111
11111
11011
In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.

Example 2:
Input: N = 2, mines = []
Output: 1
Explanation:
There is no plus sign of order 2, but there is of order 1.

Example 3:
Input: N = 1, mines = [[0, 0]]
Output: 0
Explanation:
There is no plus sign, so return 0.

Note:
N will be an integer in the range [1, 500].
mines will have length at most 5000.
mines[i] will be length 2 and consist of integers in the range [0, N-1].
(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)
*/

/*Algorithms: For each position (i,j) of the grid matrix, we try to extend in each of the four directions 
(left, right, up, down) as long as possible, then take the minimum length of 1's out of the four directions 
as the order of the largest axis-aligned plus sign centered at position (i,j).

Optimizations: Normally we would need a total of five matrices to make the above idea work -- one matrix 
for the grid itself and four more matrices for each of the four directions. However, these five matrices 
can be combined into one using two simple tricks:

For each position (i,j), we are only concerned with the minimum length of 1's out of the four directions. 
This implies we may combine the four matrices into one by only keeping tracking of the minimum length.

For each position (i,j), the order of the largest axis-aligned plus sign centered at it will be 0 if and 
only if grid[i][j] == 0. This implies we may further combine the grid matrix with the one obtained above.

Implementations:
Create an N-by-N matrix grid, with all elements initialized with value N.
Reset those elements to 0 whose positions are in the mines list.
For each position (i, j), find the maximum length of 1's in each of the four directions and set grid[i][j] 
to the minimum of these four lengths. Note that there is a simple recurrence relation relating the maximum 
length of 1's at current position with previous position for each of the four directions (labeled as l, r, u, d).
Loop through the grid matrix and choose the maximum element which will be the largest axis-aligned plus sign 
of 1's contained in the grid.

Solutions: Here is s solution based on the above ideas. It runs at O(N^2) time with O(N^2) extra space. 
Further optimizations are possible such as keeping track of the maximum plus sign currently available 
and terminating as early as possible if no larger plus sign can be found for current row/column.

Note: For those of you who got confused by the logic within the first nested for-loop, refer to andier's 
comment below for a more clear explanation.*/

class Solution {
public:
	int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
	    vector<vector<int>> grid(N, vector<int>(N, N));
	        
	    for (auto& m : mines) {
	        grid[m[0]][m[1]] = 0;
	    }
	        
	    for (int i = 0; i < N; i++) {
	    	int k = N - 1, l = 0, r = 0, u = 0, d = 0;
	        for (int j = 0; j < N; j++, k--) {
	            l = (grid[i][j] == 0 ? 0 : l + 1);
	            grid[i][j] = min(grid[i][j], l);
	            r = (grid[i][k] == 0 ? 0 : r + 1);
	            grid[i][k] = min(grid[i][k], r);
	            u = (grid[j][i] == 0 ? 0 : u + 1);
	            grid[j][i] = min(grid[j][i], u);
	            d = (grid[k][i] == 0 ? 0 : d + 1);
	            grid[k][i] = min(grid[k][i], d);
	        }
	    }
	        
	    int res = 0;
	    for (int i = 0; i < N; i++) {
	        for (int j = 0; j < N; j++) {
	            res = max(res, grid[i][j]);
	        }
	    }
	        
	    return res;
	}
};




