/*733. Flood Fill

An image is represented by a 2-D array of integers, each integer representing the pixel value of the 
image (from 0 to 65535).
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a 
pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to 
the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally 
to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all 
of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

Note:
The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

/* 这道题给了我们一个用二维数组表示的图像，不同的数字代表不同的颜色，给了我们一个起始点坐标，还有一个新的颜色，
让我们把起始点的颜色以及其相邻的同样的颜色都换成新的颜色。那么实际上就是一个找相同区间的题，我们可以用BFS或者
DFS来做。先来看BFS的解法，我们使用一个队列queue来辅助，首先将给定点放入队列中，然后进行while循环，条件是queue
不为空，然后进行类似层序遍历的方法，取出队首元素，将其赋值为新的颜色，然后遍历周围四个点，如果不越界，且周围的
颜色跟起始颜色相同的话，将位置加入队列中。不知为何，这种解法会TLE */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int r, int c, int newColor) {
        int m = image.size(), n = image[0].size();
        int color = image[r][c];
        vector<vector<int>> res = image;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        queue<pair<int, int>> q{{{r, c}}};
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto t = q.front(); 
                q.pop();
                res[t.first][t.second] = newColor;
                for (auto dir : dirs) {
                    int x = t.first + dir[0];
                    int y = t.second + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || res[x][y] != color) continue;
                    q.push({x, y});
                }
            }
        }
        return res;
    }
};


/*DFS的写法相对简洁一些，首先判断如果给定位置的颜色跟新的颜色相同的话，直接返回，否则就对给定位置调用递归函数。
在递归函数中，如果越界或者当前颜色跟起始颜色不同，直接返回。否则就给当前位置赋上新的颜色，然后对周围四个点继续
调用递归函数*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int r, int c, int newColor) {
        if (image[r][c] == newColor) return image;
        dfs(image, r, c, image[r][c], newColor);
        return image;
    }

    void dfs(vector<vector<int>>& image, int i, int j, int color, int newColor) {
        int m = image.size(), n = image[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != color) return;
        image[i][j] = newColor;
        dfs(image, i+1, j, color, newColor);
        dfs(image, i, j+1, color, newColor);
        dfs(image, i-1, j, color, newColor);
        dfs(image, i, j-1, color, newColor);
    }
};












