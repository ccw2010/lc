/* 53. Maximum Subarray 

Find the contiguous subarray within an array (containing at least one number) which 
has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide 
and conquer approach, which is more subtle.
*/

/*这道题让我们求最大子数组之和，我们先来看O(n)的解法，定义两个变量res和curSum，其中res保存最终要
返回的结果，即最大的子数组之和，curSum初始值为0，每遍历一个数字num，比较curSum + num和num中的较
大值存入curSum，然后再把res和curSum中的较大值存入res，以此类推直到遍历完整个数组，可得到最大子数
组的值存在res中 */


class Solution {
public:
    int maxSubArray(vector<int> &nums) {
    	if (nums.empty()) return 0;
        int res = INT_MIN;
        int curSum = 0;
        for (int n : nums) {
            curSum = max(curSum + n, n);
            res = max(res, curSum);
        }
        return res;
    }
};







