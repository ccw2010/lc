/* Note: This is an extension of House Robber.
After robbing those houses on that street, the thief has found himself a new place for his thievery so that 
he will not get too much attention. This time, all houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses 
remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum 
amount of money you can rob tonight without alerting the police.*/

/*这道题是之前那道House Robber 打家劫舍的拓展，现在房子排成了一个圆圈，则如果抢了第一家，就不能抢最后一家，因为首尾相连了，
所以第一家和最后一家只能抢其中的一家，或者都不抢，那我们这里变通一下，如果我们把第一家和最后一家分别去掉，各算一遍能抢的最大值，
然后比较两个值取其中较大的一个即为所求。那我们只需参考之前的House Robber 打家劫舍中的解题方法，然后调用两边取较大值*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n<=0) return 0;
        if (n==1) return nums[0];
        int x = rob(nums, 0, n-1);
        int y = rob(nums, 1, n);
        return max(x, y);
    }
    
    int rob(vector<int>& nums, int L, int R){
        if (R <= L+1) return nums[L];
        vector<int> dp(R, 0);
        dp[L] = nums[L];
        dp[L+1] = max(nums[L], nums[L+1]);
        for (int i=L+2; i< R; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[R-1];
    }
};




