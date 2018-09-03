/* 48. Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 
2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

Example 2:
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

*/


/* 在计算机图像处理里，旋转图片是很常见的，由于图片的本质是二维数组，所以也就变成了
对二维数组的操作处理，翻转的本质就是某个位置上数移动到另一个位置上，比如

1  2  3　　　 　　 7  4  1　

4  5  6　　-->　　 8  5  2　　

7  8  9 　　　 　　9  6  3

对于90度的翻转有很多方法，一步或多步都可以解，我们先来看一种直接的方法，对于当前位置，
计算旋转后的新位置，然后再计算下一个新位置，第四个位置又变成当前位置了，所以这个方法
每次循环换四个数字

1  2  3               7  2  1           7  4  1

4  5  6      -->      4  5  6　　 -->  　8  5  2　　

7  8  9               9  8  3　　　　　  9  6  3  */


class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n-1-i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1 -i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};


/* 还有一种方法，首先对原数组取其转置矩阵，然后把每行的数字翻转可得到结果

1  2  3　　　 　　 1  4  7　　　　　     7  4  1

4  5  6　　-->　　 2  5  8　　 -->  　  8  5  2　　

7  8  9 　　　 　　3  6  9　　　　      9  6  3

*/

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }   
    }
};









