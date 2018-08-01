/* 416. Partition Equal Subset Sum

Given a non-empty array containing only positive integers, find if the array can be partitioned into 
two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.

Example 1:
Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.*/


/*This problem is essentially let us to find whether there are several numbers in a set which are able to 
sum to a specific value (in this problem, the value is sum/2).

Actually, this is a 0/1 knapsack problem, for each number, we can pick it or not. Let us assume dp[i][j] 
means whether the specific sum j can be gotten from the first i numbers. If we can pick such a series of 
numbers from 0-i whose sum is j, dp[i][j] is true, otherwise it is false.

Base case: dp[0][0] is true; (zero number consists of sum 0 is true)

Transition function: For each number, if we don't pick it, dp[i][j] = dp[i-1][j], which means if the first 
i-1 elements has made it to j, dp[i][j] would also make it to j (we can just ignore nums[i]). If we pick 
nums[i]. dp[i][j] = dp[i-1][j-nums[i]], which represents that j is composed of the current value nums[i] 
and the remaining composed of other previous numbers. Thus, the transition function is 
dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]] 
*/

/*这道题给了我们一个数组，问我们这个数组能不能分成两个非空子集合，使得两个子集合的元素之和相同。那么我们想，原数组所有
数字和一定是偶数，不然根本无法拆成两个和相同的子集合，那么我们只需要算出原数组的数字之和，然后除以2，就是我们的target，
那么问题就转换为能不能找到一个非空子集合，使得其数字之和为target。开始我想的是遍历所有子集合，算和，但是这种方法无法通
过OJ的大数据集合。于是乎，动态规划 Dynamic Programming 就是我们的不二之选。我们定义一个一维的dp数组，其中dp[i]表示
数字i是否是原数组的任意个子集合之和，那么我们我们最后只需要返回dp[target]就行了。我们初始化dp[0]为true，由于题目中限
制了所有数字为正数，那么我们就不用担心会出现和为0或者负数的情况。那么关键问题就是要找出状态转移方程了，我们需要遍历原数
组中的数字，对于遍历到的每个数字nums[i]，我们需要更新dp数组，要更新[nums[i], target]之间的值，那么对于这个区间中的任
意一个数字j，如果dp[j - nums[i]]为true的话，那么dp[j]就一定为true，于是状态转移方程如下：

dp[j] = dp[j] || dp[j - nums[i]]         (nums[i] <= j <= target)

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int k = sum >> 1;

        vector<int> dp(k+1, false);
        dp[0] = 1;
        for(auto n : nums) {
            for(int j = k; j >= n; j--){
                dp[j] = dp[j] || dp[j-n];
            }
        }
        return dp[k];
    }
};


/* DFS solution: TLE */
class Solution {
public:
    bool dfs(vector<int>& nums, int start, int k) {
        if (k <= 0) return k == 0;
        for (int i = start; i < nums.size(); i++) {
            if (dfs(nums, i+1, k - nums[i])) return true;
        }
        return false;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return !(sum & 1) && dfs(nums, 0, sum / 2);
    }
};









