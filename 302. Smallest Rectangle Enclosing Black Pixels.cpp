/* 302. Smallest Rectangle Enclosing Black Pixels

An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. 
The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and 
vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) 
rectangle that encloses all black pixels.

Example:

Input:
[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2

Output: 6 */

/* 这道题给我们一个二维矩阵，表示一个图片的数据，其中1代表黑像素，0代表白像素，现在让我们找出一个最小的矩阵
可以包括所有的黑像素，还给了我们一个黑像素的坐标，我们先来看Brute Force的方法，这种方法的效率不高，遍历了
整个数组，如果遇到了1，就更新矩形的返回 */

/* Brute force, O(n^2) complexity */
class Solution {
public:
    int minArea(vector<vector<char>> &image, int x, int y) {
        if (image.empty()) return 0;
        int top = x, bottom = x;
        int left = y, right = y;
        int row = image.size();
        int col = image[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (image[i][j] == '1') {
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }
        return (bottom - top + 1) * (right - left + 1);
    }
};








