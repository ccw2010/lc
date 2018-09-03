/* 63. Unique Paths II

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

/*这道题是62.Unique Paths的延伸，在路径中加了一些障碍物，还是用动态规划Dynamic Programming来解，
不同的是当遇到为1的点，将该位置的dp数组中的值清零，其余和62.Unique Paths并没有什么区别 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid) {
        if(grid.empty() || grid[0].empty() || grid[0][0]==1) return 0;
        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) dp[i][j] = 0;
                else if(i==0 && j==0) dp[i][j] = 1;
                else if(i==0 && j>0) dp[i][j] = dp[i][j-1];
                else if(i>0 && j==0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};











