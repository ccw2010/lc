/* 287. Find the Duplicate Number 
 
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate element must exist. Assume that there is only one duplicate number, 
find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant extra space.
Your runtime complexity should be less than O(n^2).*/

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int low = 1, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (auto n : nums) {
                if (n <= mid) count++;
            }
            if (count <= mid) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};



/* 经过热心网友waruzhi的留言提醒还有一种O(n)的解法, 其核心思想快慢指针在142.Linked List Cycle II中就有应用，
由于题目限定了区间[1,n]，所以可以巧妙的利用坐标和数值之间相互转换，而由于重复数字的存在，那么一定会形成环，我们用
快慢指针可以找到环并确定环的起始位置 */

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;
        int t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        while (true) {
            slow = nums[slow];
            t = nums[t];
            if (slow == t) break;
        }
        return slow;
    }
};








