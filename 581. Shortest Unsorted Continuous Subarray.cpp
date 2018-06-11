/*581. Shortest Unsorted Continuous Subarray

Given an integer array, you need to find one continuous subarray that if you only sort this subarray 
in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=. */

/*下面这种方法是用了一个辅助数组，我们新一个跟原数组一摸一样的数组，然后排序。从数组起始位置开始，两个数组相互比较，
当对应位置数字不同的时候停止，同理再从末尾开始，对应位置上比较，也是遇到不同的数字时停止，这样中间一段就是最短无序
连续子数组了*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        vector<int> t = nums;
        sort(t.begin(), t.end());
        while (i < n && nums[i] == t[i]) {
            i++;
        }
        while (j > i && nums[j] == t[j]) {
            j--;
        }
        return j - i + 1;
    }
};





