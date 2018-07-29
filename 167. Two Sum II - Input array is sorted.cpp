/*

Given an array of integers that is already sorted in ascending order, find two numbers such
that they add up to a specific target number.The function twoSum should return indices of the
two numbers such that they add up to the target, where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same
element twice.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 */

/*O(n)的解法，我们只需要两个指针，一个指向开头，一个指向末尾，然后向中间遍历，如果指向的两个数相加正好等于
target的话，直接返回两个指针的位置即可，若小于target，左指针右移一位，若大于target，右指针左移一位，以此
类推直至两个指针相遇停止*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left < right){
            int x = nums[left] + nums[right];
            if (x > target) right--; 
            else if (x < target) left++;
            else return {left+1, right+1};
        }
        return {};
    }
};







