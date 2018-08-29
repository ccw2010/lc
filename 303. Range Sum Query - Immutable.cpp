/*303 Range Sum Query - Immutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
 
这道题让我们检索一个数组的某个区间的所有数字之和，题目中给了两条条件，首先数组内容不会变化，其次有很多的区间和检索。
那么我们用传统的遍历相加来求每次区间和检索，十分的不高效，而且无法通过OJ。所以这道题的难点就在于是否能想到来用建立
累计直方图的思想来建立一个累计和的数组dp，其中dp[i]表示[0, i]区间的数字之和，那么[i,j]就可以表示为dp[j]-dp[i-1]，
这里要注意一下当i=0时，直接返回dp[j]即可，参见代码如下：
*/

class NumArray {
private:
    vector<int> dp;
    
public:
    NumArray(vector<int> &nums) {
        dp = nums;
        int n = nums.size();
        for (int i = 1; i < n; i++){
            dp[i] += dp[i-1];
        }   
    }
    
    int sumRange(int i, int j) {
        if (i==0) return dp[j];
        else return dp[j] - dp[i-1];
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */







