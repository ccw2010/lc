/*695. Max Area of Island
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are 
surrounded by water. Find the maximum area of an island in the given 2D array. (If there is no island, 
the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

Given the above grid, return 6. Note the answer is not 11, because the island must be connected 
4-directionally.

Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50. */


/* 这道题跟200. Number of Islands, 305. Number of Islands II 和 694.Number of Distinct Islands 
是同一个类型的，只不过这次需要统计出每个岛的大小，再来更新结果res。先用递归来做，遍历grid，当遇到为1的点，
我们调用递归函数，在递归函数中，我们首先判断i和j是否越界，还有grid[i][j]是否为1，我们没有用visited数组，
而是直接修改了grid数组，遍历过的标记为-1。如果合法，那么cnt自增1，并且更新结果res，然后对其周围四个相邻
位置分别调用递归函数即可*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int count = 0;
                dfs(grid, i, j, count, res);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int &count, int &res) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> nbrs{{0,-1},{-1,0},{0,1},{1,0}};
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return;
        res = max(res, ++count);
        grid[i][j] = -1;
        for (auto nbr : nbrs) {
            dfs(grid, i + nbr[0], j + nbr[1], count, res);
        }
    }
};










