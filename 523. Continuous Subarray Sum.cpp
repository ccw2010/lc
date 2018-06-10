/*523. Continuous Subarray Sum

Given a list of non-negative numbers and a target integer k, write a function to check if the 
array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, 
sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.

Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.*/

/*这道题给了我们一个数组和一个数字k，让我们求是否存在这样的一个连续的子数组，该子数组的数组之和可以整除k。
遇到除法问题，我们肯定不能忘了除数为0的情况等处理。还有就是我们如何能快速的遍历所有的子数组，并且求和，肯定不能完全
暴力破解，需要适当的优化。遇到这种求子数组或者子矩阵之和的题，应该不难想到要建立累加和数组或者累加和矩阵来做。这道题
也得这么做，我们要遍历所有的子数组，然后利用累加和来快速求和。在得到每个子数组之和时，我们先和k比较，如果相同直接返回
true，否则再判断，若k不为0，且sum能整除k，同样返回true，最后遍历结束返回false*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = nums[i];
            for (int j = i+1; j < n; j++) {
                sum += nums[j];
                if (k == 0 && sum == k) return true;
                else if (k != 0 && sum % k == 0) return true;
            }
        }
        return false;
    }
};








