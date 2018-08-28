/* 286. Walls and Gates 
 
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may 
assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it 
should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4*/
 

/* 这道题类似一种迷宫问题，规定了-1表示墙，0表示门，让求每个点到门的最近的曼哈顿距离，这其实类似于求距离场Distance Map的问题，
那么我们先考虑用DFS来解，思路是，我们搜索0的位置，每找到一个0，以其周围四个相邻点为起点，开始DFS遍历，并带入深度值1，如果遇到
的值大于当前深度值，我们将位置值赋为当前深度值，并对当前点的四个相邻点开始DFS遍历，注意此时深度值需要加1，这样遍历完成后，所有
的位置就被正确地更新了 */
 
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()) return;
        size_t row = rooms.size();
        size_t col = rooms[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (rooms[i][j] == 0) dfs(rooms, i, j, 0);
            }
        }
    }
    void dfs(vector<vector<int>>& rooms, int i, int j, int val) {
        if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[i].size() || rooms[i][j] < val) return;
        rooms[i][j] = val;
        dfs(rooms, i + 1, j, val + 1);
        dfs(rooms, i - 1, j, val + 1);
        dfs(rooms, i, j + 1, val + 1);
        dfs(rooms, i, j - 1, val + 1);
    }
};

 
/* 再来看BFS的解法，需要借助queue，我们首先把门的位置都排入queue中，然后开始循环，对于门位置的四个相邻点，我们判断其
是否在矩阵范围内，并且位置值是否大于上一位置的值加1，如果满足这些条件，我们将当前位置赋为上一位置加1，并将次位置排入
queue中，这样等queue中的元素遍历完了，所有位置的值就被正确地更新了 */

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()) return;
        queue<pair<int, int>> q;
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        size_t row = rooms.size(), col = rooms[0].size();
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                if (rooms[i][j] == 0) q.push({i, j});   
            }
        }
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second; 
            q.pop();
            for (size_t k = 0; k < dirs.size(); k++) {
                int x = i + dirs[k][0];
                int y = j + dirs[k][1];
                if (x < 0 || x >= row || y < 0 || y >= col || rooms[x][y] < rooms[i][j] + 1) continue;
                rooms[x][y] = rooms[i][j] + 1;
                q.push({x, y});
            }
        }
        
    }
};










