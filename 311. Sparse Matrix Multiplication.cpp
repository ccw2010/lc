/*311. Sparse Matrix Multiplication 稀疏矩阵相乘
 
Given two sparse matrices A and B, return the result of AB.
You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
 
这道题让我们实现稀疏矩阵相乘，稀疏矩阵的特点是矩阵中绝大多数的元素为0，而相乘的结果是还应该是稀疏矩阵，即还是大多数元素为0，
那么我们使用传统的矩阵相乘的算法肯定会处理大量的0乘0的无用功，所以我们需要适当的优化算法，使其可以顺利通过OJ，我们知道一个 
i x k 的矩阵A乘以一个 k x j 的矩阵B会得到一个 i x j 大小的矩阵C，那么我们来看结果矩阵中的某个元素C[i][j]是怎么来的，
起始是A[i][0]*B[0][j] + A[i][1]*B[1][j] + ... + A[i][k]*B[k][j]，那么为了不重复计算0乘0，我们首先遍历A数组，要确保
A[i][k]不为0，才继续计算，然后我们遍历B矩阵的第k行，如果B[k][j]不为0，我们累加结果矩阵res[i][j] += A[i][k] * B[k][j]; 
这样我们就能高效的算出稀疏矩阵的乘法 */

/* Note:
The standard multiplication of an m-by-k matrix by an k-by-n matrix has complexity O(mkn). 
If all of those are "n" to you, it's O(n^3), not O(n^2). 
EDIT: it will not be O(n^2) in the general case. But there are faster algorithms for particular 
types of matrices -- if you know more you may be able to do better.*/


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        size_t rowA = A.size(), colA = A[0].size();
        size_t rowB = B.size(), colB = B[0].size();
        vector<vector<int>> res(rowA, vector<int>(colB));
        
        for (size_t i = 0; i < rowA; i++) {
            for (size_t k = 0; k < colA; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < colB; j++) {
                    if (B[k][j] == 0) continue;
                    res[i][j] += A[i][k] * B[k][j];
                }            
            }
        }
        return res;
    }
};









