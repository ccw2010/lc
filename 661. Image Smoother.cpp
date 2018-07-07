/*661. Image Smoother

Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to 
make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding 
cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0 */

/* 这道题让我们给一个图片进行平滑处理，一般来说都是用算子来跟图片进行卷积，这道题我们直接用土办法就能解了，
就直接对于每一个点统计其周围点的个数，然后累加像素值，做个除法 */

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& m) {
        if (m.empty() || m[0].empty()) return {};
        int row = m.size(), col = m[0].size();
        vector<vector<int>> res = m;
        vector<vector<int>> dirs {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int total = m[i][j];
                int nbrs = 1;
                for (auto dir : dirs) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x < 0 || x >= row || y < 0 || y >= col) continue;
                    nbrs++;
                    total += m[x][y];
                }
                res[i][j] = total / nbrs;
            }
        }
        return res;
    }
};










