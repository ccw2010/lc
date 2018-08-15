/*280. Wiggle Sort

Given an unsorted array nums, reorder it in-place such that 
nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:
Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]*/


// Time Complexity O(nlogn)
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
    	if (n <= 2) return;
        sort(nums.begin(), nums.end());
        for (int i = 2; i < n; i += 2) {
            swap(nums[i], nums[i-1]);
        }
    }
};

/*还有一种O(n)的解法，根据题目 nums[0] <= nums[1] >= nums[2] <= nums[3]...，可总结如下规律：
当i为奇数时，nums[i] >= nums[i - 1]
当i为偶数时，nums[i] <= nums[i - 1]
那么我们只要对每个数字，根据其奇偶性，跟其对应的条件比较，如果不符合就和前面的数交换位置即可*/

// Time Complexity O(n)
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        if (nums.size() <= 1) return;
        for (int i = 1; i < nums.size(); i++) {
            if ((i % 2 == 1 && nums[i] < nums[i-1]) || (i % 2 == 0 && nums[i] > nums[i-1])) {
                swap(nums[i], nums[i-1]);
            }
        }
    }
};






