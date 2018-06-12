/*84. Largest Rectangle in Histogram
https://leetcode.com/problems/largest-rectangle-in-histogram/description/

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 
The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:
Input: [2,1,5,6,2,3]
Output: 10
*/

/*这道题让求直方图中最大的矩形，刚开始看到求极值问题以为要用DP来做，可是想不出递推式。这道题如果用暴力搜索法肯定没法通过OJ，
网上有一种很好的优化方法，就是遍历数组，每找到一个局部峰值，然后向前遍历所有的值，算出共同的矩形面积，每次对比保留最大值 */

// Pruning optimize
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            if (i+1 < n && height[i] <= height[i+1]) {
                continue;
            }
            int minH = height[i];
            for (int j = i; j >= 0; j--) {
                minH = min(minH, height[j]);
                int area = minH * (i-j+1);
                res = max(res, area);
            }
        }
        return res;
    }
};









