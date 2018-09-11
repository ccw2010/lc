/*209. Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous 
subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 
Input: k = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(nlogn). 
*/

/*这道题给定了我们一个数字，让我们求子数组之和大于等于给定值的最小长度，跟之前那道 Maximum Subarray 最大子数组有些类似，
并且题目中要求我们实现O(n)和O(nlgn)两种解法，那么我们先来看O(n)的解法，我们需要定义两个指针left和right，分别记录子数组的
左右的边界位置，然后我们让right向右移，直到子数组和大于等于给定值或者right达到数组末尾，此时我们更新最短距离，并且将left像
右移一位，然后再sum中减去移去的值，然后重复上面的步骤，直到right到达末尾，且left到达临界位置，即要么到达边界，要么再往右移动，
和就会小于给定值。*/

// O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.empty()) return 0;
        int i = 0, j = 0;
        int n = nums.size(), res = n + 1;
        int sum = 0;
        while (j < n) {
            while (sum < s && j < n) {
                sum += nums[j];
                j++;
            }
            while (sum >= s) {
                res = min(res, j - i);
                sum -= nums[i];
                i++;
            }
        }
        if (res > n) return 0;
        else return res;
    }
};

/*再来看看O(nlgn)的解法，这个解法要用到二分查找法，思路是，我们建立一个比原数组长一位的sums数组，
其中sums[i]表示nums数组中[0, i-1]的和，然后我们对于sums中每一个值sums[i]，用二分查找法找到子数组的
右边界位置，使该子数组之和大于sums[i] + k */

class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int res = INT_MAX, n = nums.size();
        vector<int> sums(n+1, 0);
        for (int i=1; i < n+1; i++) {
            sums[i] = sums[i-1] + nums[i-1];
        }
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n;
            int t = sums[i] + k;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (sums[mid] < t) left = mid + 1;
                else right = mid - 1;
            }
            if (left == n + 1) break;
            res = min(res, left - i);
        }
        return res == INT_MAX ? 0 : res;
    }
};





