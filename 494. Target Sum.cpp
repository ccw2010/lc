/* 494. Target Sum

You are given a list of non-negative integers, a1, a2, ..., an, and a target, k. Now you have 
2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target k.

Example 1:
Input: nums is [1, 1, 1, 1, 1], k is 3. 
Output: 5

Explanation: 
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.*/

/*这道题给了我们一个数组，和一个目标值，让我们给数组中每个数字加上正号或负号，然后求和要和目标值相等，
求有多少中不同的情况。那么对于这种求多种情况的问题，我最想到的方法使用递归来做。我们从第一个数字，
调用递归函数，在递归函数中，分别对目标值进行加上当前数字调用递归，和减去当前数字调用递归，这样会涵盖
所有情况，并且当所有数字遍历完成后，我们看若目标值为0了，则结果res自增1*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int k) {
        int res = 0;
        helper(nums, k, 0, res);
        return res;
    }
    void helper(vector<int>& nums, int k, int start, int& res) {
        if (start >= nums.size()) {
            if (k == 0) ++res;
            return;
        }
        helper(nums, k - nums[start], start + 1, res);
        helper(nums, k + nums[start], start + 1, res);
    }
};


/*对上面的递归方法进行优化，使用dp数组来记录中间值，这样可以避免重复运算*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        return helper(nums, k, 0, dp);
    }
    int helper(vector<int>& nums, int sum, int start, vector<unordered_map<int, int>>& dp) {
        if (start == nums.size()) return sum == 0;
        if (dp[start].count(sum)) return dp[start][sum];
        int count1 = helper(nums, sum - nums[start], start + 1, dp);
        int count2 = helper(nums, sum + nums[start], start + 1, dp);
        return dp[start][sum] = count1 + count2;
    }
};


/*我们也可以使用迭代的方法来解，还是要用dp数组，其中dp[i][j]表示到第i-1个数字且和为j的情况总数*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (auto &a : dp[i]) {
                int sum = a.first;
                int count = a.second;
                dp[i+1][sum + nums[i]] += count;
                dp[i+1][sum - nums[i]] += count;
            }
        }
        return dp[n][k];
    }
};








