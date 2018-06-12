/* 454. 4Sum II

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that 
A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 2^31 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output: 2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0 */

/*这道题是之前那道4Sum的延伸，让我们在四个数组中各取一个数字，使其和为0。Brute force方法就是遍历所有的情况，时间复杂度为O(n^4)。
但是想想既然Two Sum那道都能将时间复杂度缩小一倍，那么这道题我们使用哈希表是否也能将时间复杂度降到O(n^2)呢？答案是肯定的，我们如果
把A和B的两两之和都求出来，在哈希表中建立两数之和跟其出现次数之间的映射，那么我们再遍历C和D中任意两个数之和，我们只要看哈希表存不存
在这两数之和的相反数就行了*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> m;
        int sum = 0, target = 0;
        int len1 = A.size(), len2 = B.size();
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                sum = A[i] + B[j];
                m[sum]++;
            }
        }
        int len3 = C.size(), len4 = D.size();
        for (int i = 0; i < len3; i++) {
            for (int j = 0; j < len4; j++) {
                target = -1 * (C[i] + D[j]);
                res += m[target];
            }
        }
        return res;
    }
};













