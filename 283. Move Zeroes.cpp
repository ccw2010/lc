/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the 
non-zero elements. For example, given nums = [0, 1, 0, 3, 12], after calling the function, nums should be [1, 3, 12, 0, 0]. */

// 需要用两个指针，一个不停的向后扫，找到非零位置，然后和前面那个指针交换位置即可

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        // move all the nonzero elements advance
        for (auto n : nums) {
            if (n) nums[j++] = n;
        }
        for (; j < n; j++) {
            nums[j] = 0;
        }
    }
};




