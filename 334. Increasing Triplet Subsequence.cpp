/*334. Increasing Triplet Subsequence

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

    Return true if there exists i, j, k
    such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false. 

Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.*/


/*题目中要求我们O(n)的时间复杂度和O(1)的空间复杂度，我们下面来看满足题意的方法，这个思路是使用两个数first和second，
初始化为整型最大值，我们遍历数组，如果当前数字小于等于second，则将当前数字赋给second；如果当前数字大于second且小于等于
first，那么将当前数字赋给first，一旦first被更新了，说明一定会有2个数小于first，那么我们就成功的组成了一个长度为2的递增
子序列，所以我们一旦遍历到比first还大的数，我们直接返回ture。如果我们遇到比second小的数，还是要更新second，有可能的话也
要更新first为更小的值，毕竟first的值越小，能组成长度为3的递增序列的可能性越大*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    	if (nums.size() < 3) return false;
        int first = INT_MAX, second = INT_MAX;
        for (auto n : nums) {
            if ( n <= second) second = n;
            else if (n > second && n <= first) first = n;
            else if (n > first) return true;
        }
        return false;
    }
};


/*上面的解法不容易想出来，下面这种解法虽然不满足常数空间的要求，但是作为对暴力搜索的优化，也是一种非常好的解题思路。
这个解法的思路是建立两个数组，forward数组和backward数组，其中forward[i]表示[0, i]之间最小的数，backward[i]表示
[i, n-1]之间最大的数，那么对于任意一个位置i，如果满足 forward[i] < nums[i] < backward[i]，则表示这个递增三元子
序列存在，举个例子来看吧，比如：

nums:        8  3  5  1  6

foward:      8  3  3  1  1

backward:    8  6  6  6  6

我们发现数字5满足forward[i] < nums[i] < backward[i]，所以三元子序列存在。
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    	int n = nums.size();
        if (n < 3) return false;
        vector<int> f(n, nums[0]);
        vector<int> b(n, nums.back());
        for (int i = 1; i < n; i++) {
            f[i] = min(f[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            b[i] = max(b[i + 1], nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > f[i] && nums[i] < b[i]) return true;
        }
        return false;
    }
};




