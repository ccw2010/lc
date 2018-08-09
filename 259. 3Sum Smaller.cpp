/* 259. 3Sum Smaller

Given an array of n integers nums and a target, find the number of index triplets i, j, k with 
0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Example:
Input: nums = [-2,0,1,3], and target = 2
Output: 2 
Explanation: Because there are two triplets which sums are less than 2:
             [-2,0,1]
             [-2,0,3] */

/* 题目中的Follow up让我们在O(n^2)的时间复杂度内实现，那么我们借鉴之前3Sum Closest和3Sum中的方法，采用双指针来做，
这里面有个trick就是当判断三个数之和小于目标值时，此时结果应该加上right-left，以为数组排序了以后，如果加上num[right]
小于目标值的话，那么加上一个更小的数必定也会小于目标值，然后我们将左指针右移一位，否则我们将右指针左移一位 */

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; i++){
            int left = i+1, right = n-1;
            while (left < right){
                if (nums[i] + nums[left] + nums[right] < target){
                    res += right - left;
                    left++; 
                } else{
                    right--;
                }
            }
        }
        return res;  
    }
};












