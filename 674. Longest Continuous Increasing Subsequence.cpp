/*674. Longest Continuous Increasing Subsequence

Given an unsorted array of integers, find the length of longest continuous increasing subarray.

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are 
separated by 4. 

Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. */

/*这道题让我们求一个数组的最长连续递增序列，由于有了连续这个条件，跟673.Number of Longest Increasing Subsequence
比起来，难度就降低了很多。我们可以使用一个计数器，如果遇到大的数字，计数器自增1, 并update res；如果是一个小的数字，则
计数器重置为1。最后返回res即可*/

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int res = 0, count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i-1] < nums[i]) {
                count++;
                res = max(res, count);
            } else {
                count = 1;
            }
        }
        return res;
    }
};












