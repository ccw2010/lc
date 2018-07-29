/* 442. Find All Duplicates in an Array

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice 
and others appear once. Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[2,3]
*/

/*这道题给了我们一个数组，数组中的数字可能出现一次或两次，让我们找出所有出现两次的数字，有一道类似的题目
Find the Duplicate Number。这类问题的一个重要条件就是1 ≤ a[i] ≤ n (n = size of array)，不然很难在
O(1)空间和O(n)时间内完成。首先来看一种正负替换的方法，这类问题的核心是就是找nums[i]和nums[nums[i] - 1]
的关系，我们的做法是，对于每个nums[i]，我们将其对应的nums[nums[i] - 1]取相反数，如果其已经是负数了，
说明之前存在过，我们将其加入结果res中即可*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int &n : nums) {
            int idx = abs(n) - 1;
            if (nums[idx] < 0) res.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }
        return res;
    }
};







