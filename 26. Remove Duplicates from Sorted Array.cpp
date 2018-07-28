/* 26. Remove Duplicates from Sorted Array

Given a sorted array nums, remove the duplicates in-place such that each element appear only once 
and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place
 with O(1) extra memory.

Example 1:
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, 
and 4 respectively.
It doesn't matter what values are set beyond the returned length.

这道题要我们从有序数组中去除重复项，和Remove Duplicates from Sorted List(移除有序链表中的重复项) 
的题很类似，但是要简单一些，因为数组的值可以通过下标直接访问，而链表不行。那么这道题的解题思路是，
我们使用快慢指针来记录遍历的坐标，最开始时两个指针都指向第一个数字，
如果两个指针指的数字相同，则快指针向前走一步，如果不同，则两个指针都向前走一步，
这样当快指针走完整个数组后，慢指针当前的坐标加1就是数组中不同数组的个数*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {       
        if (nums.empty()) return 0;
        int j=0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] != nums[j]){
                nums[++j] = nums[i];
            }
        }
        return j+1;
    }
};








