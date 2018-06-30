/* 448  Find All Numbers Disappeared in an Array

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and 
others appear once. Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not 
count as extra space.

Example:
Input: [4,3,2,7,8,2,3,1]

Output: [5,6]*/

/*这道题让我们找出数组中所有消失的数，这类问题的一个重要条件就是1 ≤ a[i] ≤ N (size of array)，不然很难在O(1)空间
和O(n)时间内完成。一种解法的思路路是，对于每个数字nums[i]，如果其对应的nums[nums[i] - 1]是正数，我们就赋值为其相反数，
如果已经是负数了，就不变了，那么最后我们只要把留下的整数对应的位置加入结果res中即可*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty()) return {};
        
        // Iterate each number in nums (find existing numbers) 
        for (int n : nums){
            int idx = abs(n) - 1;
            nums[idx] = -1 * abs(nums[idx]);
        }
        // Iterate each number in range of 1 <= x <= N (find missing numbers)
        vector<int> res;
        int len = nums.size();
        for (int i=0; i<len; i++){
            if (nums[i]>0) res.push_back(i+1);        
        }
        return res;
    }
};









