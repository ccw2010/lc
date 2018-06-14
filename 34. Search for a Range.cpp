/*34. Search for a Range
Given an array of integers nums sorted in ascending order, find the starting and ending position 
of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

/*这道题让我们在一个有序整数数组中寻找相同目标值的起始和结束位置，而且限定了时间复杂度为O(logn)，
这是典型的二分查找法的时间复杂度，所以这道题我们也需要用此方法，我们的思路是首先对原数组使用二分查找法，
找出其中一个目标值的位置，然后向两边搜索找出起始和结束的位置*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int k) {
        int n = nums.size();
        int idx = search(nums, 0, n-1, k);
        if (idx == -1) return {-1, -1};
        
        int left = idx, right = idx;
        while (left > 0 && nums[left-1] == nums[idx]) {
            left--;
        }
        while (right < n-1 && nums[right+1] == nums[idx]) {
            right++;
        }
        return {left, right};
    }
    
    int search(vector<int>& nums, int left, int right, int k) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == k) {
            return mid;
        } else if (nums[mid] < k) {
            return search(nums, mid + 1, right, k);
        } else {
            return search(nums, left, mid - 1, k);
        }
    }
};














