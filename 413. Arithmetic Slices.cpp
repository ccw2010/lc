/* 413. Arithmetic Slices

A sequence of number is called arithmetic if it consists of at least three elements and if the 
difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic.
1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of 
integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

Example:
A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.*/

/*这道题让我们算一种算数切片，说白了就是找等差数列，限定了等差数列的长度至少为3，那么[1,2,3,4]含有3个长度至少为3
的算数切片，我们再来看[1,2,3,4,5]有多少个呢:
len = 3: [1,2,3], [2,3,4], [3,4,5]
len = 4: [1,2,3,4], [2,3,4,5]
len = 5: [1,2,3,4,5]
那么我们可以找出递推式，长度为n的等差数列中含有长度至少为3的算数切片的个数为(n-1)(n-2)/2，那么题目就变成了找原数组中
等差数列的长度，然后带入公式去算个数即可*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, len = 2, n = A.size();
        for (int i = 2; i < n; ++i) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                len++;
            } else {
                if (len >= 3) res += (len - 1) * (len - 2) / 2;
                len = 2;
            }
        }
        if (len >= 3) res += (len - 1) * (len - 2) / 2;
        return res;
    }
};

/*我们还可以用DP来做，定义一个一维dp数组，其中dp[i]表示，到i位置为止的算数切片的个数，那么我们从第三个数字开始遍历，
如果当前数字和之前两个数字构成算数切片，那么我们更新dp[i]为dp[i-1]+1，然后res累加上dp[i]的值即可*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, n = A.size();
        vector<int> dp(n, 0);
        for (int i = 2; i < n; i++) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp[i] = dp[i-1] + 1;
            }
            res += dp[i];
        }
        return res;
    }
};








