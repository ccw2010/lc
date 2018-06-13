/*280. Wiggle Sort

Given an unsorted array nums, reorder it in-place such that 
nums[0] <= nums[1] >= nums[2] <= nums[3]....

Example:
Input: nums = [3,5,2,1,6,4]
Output: One possible answer is [3,5,1,6,2,4]*/

/*这道题让我们求摆动排序，跟 324.Wiggle Sort II相比起来，这道题的条件宽松很多，只因为多了一个等号。
由于等号的存在，当数组中有重复数字存在的情况时，也很容易满足题目的要求。这道题我们先来看一种时间复杂度为O(nlgn)的方法，
思路是先给数组排个序，然后我们只要每次把第一个数和第二个数调换个位置，第三个数和第四个数调换个位置，以此类推直至数组末尾，
这样我们就能完成摆动排序了*/

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
        int n = nums.size();
        if (n <= 1) return;
        bool isOdd;
        for (int i = 1; i < n; i++) {
            isOdd = (i&1)? true : false;
            if ((isOdd && nums[i] < nums[i-1]) || (!isOdd && nums[i] > nums[i-1])) {
                swap(nums[i], nums[i-1]);
            }
        }
    }
};






