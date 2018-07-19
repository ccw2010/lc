/*16. 3Sum Closest
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is 
closest to target. Return the sum of the three integers. You may assume that each input would have exactly 
one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

/*这道题让我们求最接近给定值的三数之和，是在 15.3Sum 三数之和的基础上又增加了些许难度，那么这道题让我们返回这个
最接近于给定值的值，即我们要保证当前三数和跟给定值之间的差的绝对值最小，所以我们需要定义一个变量diff用来记录差的绝对值，
然后我们还是要先将数组排个序，然后开始遍历数组，思路跟那道三数之和很相似，都是先确定一个数，然后用两个指针left和right来
滑动寻找另外两个数，每确定两个数，我们求出此三数之和，然后算和给定值的差的绝对值存在newDiff中，然后和diff比较并更新diff
和结果closest即可*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(closest - target);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int k = 0; k < n - 2; k++) {
            int i = k + 1, j = n - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                int newDiff = abs(sum - target);
                if (newDiff < diff) {
                    diff = newDiff;
                    closest = sum;
                }
                if (sum < target) i++;
                else j--;
            }
        }
        return closest;
    }
};








