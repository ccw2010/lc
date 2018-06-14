/*312. Burst Balloons
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented 
by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get 
nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After 
the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.

Note:
You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:
Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

*/

/*
the visualization help me to understand hope it can help you too.

1···················1

add two 1 at beginning and end of nums, each · represent each number in nums.

len is the subinterval length, it grows from 1 to full length of orignal nums string.

the following illustrations demonstrate how the subinterval shift from left to right. 
(len = 7 in the illustration)

for each len, when shifted to rightmost, increase len and do the shift again. this way we can evaluate
 all possible subintervals.

for each subinterval, in the innermost for loop, find which balloon to burst LAST that will give us 
the most coins for that subinterval. <- IMPORTANT TO UNDERSTAND THIS

dp[left][right] is the maximum coins we can get from left to right. note when left > right, it is 0

   1···················1    (len = 7)
    |     |
  left  right
  
   1···················1
           |     |
         left  right
          
   1···················1
                |     |
              left  right

for the example [3, 1, 5, 8], the dp matrix is updated like this
0    0    0    0    0    0
0    3    0    0    0    0
0    0    15   0    0    0
0    0    0    40   0    0
0    0    0    0    40   0
0    0    0    0    0    0

then
0    0    0    0    0    0
0    3    30   0    0    0
0    0    15   135  0    0
0    0    0    40   48   0
0    0    0    0    40   0
0    0    0    0    0    0

at last
0    0    0    0    0    0
0    3    30   159  167  0
0    0    15   135  159  0
0    0    0    40   48   0
0    0    0    0    40   0
0    0    0    0    0    0

the code is like most others.*/


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n1 = nums.size();
        vector<vector<int>> dp(n1, vector<int>(n1 , 0));
        for (int k = 1; k <= n; k++) {
            for (int left = 1; left <= n-k+1; left++) {
                int right = left + k - 1;
                for (int i = left; i <= right; i++) {
                    int coins = nums[left-1] * nums[i] * nums[right+1] + dp[left][i-1] + dp[i+1][right];
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }
        return dp[1][n];
    }
};







