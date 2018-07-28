/*256. Paint House
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. 
The cost of painting each house with a certain color is different. You have to paint all the houses such 
that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, 
costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 
with color green, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:
Input: [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue. 
             Minimum cost: 2 + 5 + 3 = 10. */

/*这道题说有n个房子，每个房子可以用红绿蓝三种颜色刷，每个房子的用每种颜色刷的花费都不同，限制条件是相邻的房子不能用
相同的颜色来刷，现在让我们求刷完所有的房子的最低花费是多少。这题跟House Robber II和House Robber很类似，不过那题不是
每个房子都抢，相邻的房子不抢，而这道题是每个房子都刷，相邻的房子不能刷同一种颜色。而Paint Fence那道题主要考察我们有多
少种刷法，这几道题很类似，但都不一样，需要我们分别区分。但是它们的解题思想都一样，需要用动态规划Dynamic Programming
来做，这道题我们需要维护一个二维的动态数组dp，其中dp[i][j]表示刷到第i+1房子用颜色j的最小花费，递推式为:

dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2]);
dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2]);
dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1]);

这个也比较好理解，如果当前的房子要用红色刷，那么上一个房子只能用绿色或蓝色来刷，那么我们要求刷到当前房子，且当前房子用
红色刷的最小花费就等于当前房子用红色刷的钱加上刷到上一个房子用绿色和刷到上一个房子用蓝色的较小值，这样当我们算到最后一
个房子时，我们只要取出三个累计花费的最小值即可*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty()) return 0;
        vector<vector<int>> dp = costs;
        int n = costs.size();
        for (int i=1; i<n; i++){
            dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
        }
        vector<int> last = dp[n-1];
        return min(last[0], min(last[1], last[2]));
    }
};










