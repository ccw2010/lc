/* 62.Unique Paths I

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the 
bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

bove is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3
Output: 28
*/

/*这道题让求所有不同的路径的个数，这跟70.Climbing Stairs 很类似，那道题是说可以每次能爬一格或两格，问到达顶部的
所有不同爬法的个数。而这道题是每次可以向下走或者向右走，求到达最右下角的所有不同走法的个数。那么跟爬梯子问题一样，
我们需要用动态规划Dynamic Programming来解，我们可以维护一个二维数组dp，其中dp[i][j]表示到当前位置不同的走法的个数，
然后可以得到递推式为: 
dp[i][j] = dp[i-1][j] + dp[i][j-1]
从左上角开始，由这个递推公式，往右下角递归即可：*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        if (m==1 || n==1) return 1;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


/*为了节省空间，也可使用一维数组dp，一行一行的刷新也可以*/
int uniquePaths(int m, int n){
	if (m<1 || n<1) return 0;
	if (m==1 || n==1) return 1;
	vector<int> dp(n, 1);
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			dp[j] += dp[j-1];
		}
	}
	return dp.back();
}


