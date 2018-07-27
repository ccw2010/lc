/* 238. Product of Array Except Self

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to 
the product of all the elements of nums except nums[i].

Example:
Input:  [1,2,3,4]
Output: [24,12,8,6]

Note: Please solve it without division and in O(n).

Follow up: Could you solve it with constant space complexity? (The output array does not count as extra 
space for the purpose of space complexity analysis.) */


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fwd(n, 1), bwd(n, 1), res(n);
        for (int i = 0; i < n - 1; i++) {
            fwd[i + 1] = fwd[i] * nums[i];
        }
        for (int i = n - 1; i > 0; i--) {
            bwd[i - 1] = bwd[i] * nums[i];
        }
        for (int i = 0; i < n; i++) {
            res[i] = fwd[i] * bwd[i];
        }
        return res;
    }
};





