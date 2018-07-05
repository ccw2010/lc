/*64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which 
minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

/*This is a typical DP problem. Suppose the minimum path sum of arriving at point (i, j) is dp[i][j], 
then the state equation is dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j].

Well, some boundary conditions need to be handled. The boundary conditions happen on the topmost row 
(dp[i-1][j] does not exist) and the leftmost column (dp[i][j-1] does not exist). Suppose grid is like 
[1, 1, 1, 1], then the minimum sum to arrive at each point is simply an accumulation of previous points 
and the result is [1, 2, 3, 4].

Now we can write down the following (unoptimized) code.
*/

/*这道题174.Dungeon Game 地牢游戏 没有什么太大的区别，都需要用动态规划Dynamic Programming来做，我们维护一个二维
的dp数组，其中dp[i][j]表示当前位置的最小路径和，递推式也容易写出来:
dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
*/

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int row = grid.size();
        int col = grid[0].size();
        int dp[row][col];
        dp[0][0] = grid[0][0]; 
        for (int i = 1; i < row; i++) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for (int j = 1; j < col; j++) {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[row-1][col-1];
    }
};








