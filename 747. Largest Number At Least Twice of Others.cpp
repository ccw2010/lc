/*747. Largest Number At Least Twice of Others
In a given integer array nums, there is always exactly one largest element.
Find whether the largest element in the array is at least twice as much as every other number in the array.
If it is, return the index of the largest element, otherwise return -1.

Example 1:
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.

Example 2:
Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.*/

/*这道题让我们找一个至少是其他数字两倍的最大数字，那么我们想，首先明确的一点是这个要求的数字一定是数组中的最大数字，
因为其是其他所有的数字的至少两倍。我们可以使用简单粗暴的方法，首先遍历一遍数组找出最大数字，然后再遍历一遍数组，验证
这个数字是否是其他数字的至少两倍*/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxVal = INT_MIN;
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > maxVal){
                maxVal = nums[i];
                res = i;
            }
        }
        for (int n : nums){
            if (maxVal != n && maxVal-n < n) return -1;
        }
        return res;
    }
};












