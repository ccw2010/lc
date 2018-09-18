/* 287. Find the Duplicate Number 
 
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate element must exist. Assume that there is only one duplicate number, 
find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant extra space.
Your runtime complexity should be less than O(n^2).*/


/*这道题给了我们n+1个数，所有的数都在[1,n]区域内，首先让我们证明必定会有一个重复数。题目要求我们不能改变原数组，
不能给原数组排序，又不能用多余空间，那么哈希表也就不用考虑了，又说时间小于O(n2)，也就不能用brute force的方法，
那也只能考虑用二分搜索法了，我们在区别[1, n]中搜索，首先求出中点mid，然后遍历整个数组，统计所有小于等于mid的数
的个数，如果个数大于mid，则说明重复值在[mid+1, n]之间，反之，重复值应在[1, mid-1]之间，然后依次类推，直到搜索
完成，此时的low就是我们要求的重复值 */

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


/* 还有一种O(n)的解法, 其核心思想快慢指针在142.Linked List Cycle II中就有应用，由于题目限定了区间[1,n]，
所以可以利用坐标和数值之间相互转换，而由于重复数字的存在，那么一定会形成环，我们用快慢指针可以找到环并确定环的
起始位置 */

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








