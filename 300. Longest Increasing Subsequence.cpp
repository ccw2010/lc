/* 300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:
Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 

Note:
There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?*/

/*这道题让我们求最长递增子串的长度，简称LIS的长度。先来看一种动态规划Dynamic Programming的解法，这种解法的时间复杂度为O(n^2)，
类似brute force的解法，我们维护一个一维dp数组，其中dp[i]表示以nums[i]为结尾的最长递增子串的长度，对于每一个nums[i]，我们从第
一个数再搜索到i，如果发现某个数小于nums[i]，我们更新dp[i]，更新方法为dp[i] = max(dp[i], dp[j] + 1)，即比较当前dp[i]的值和那
个小于num[i]的数的dp值加1的大小，我们就这样不断的更新dp数组，到最后dp数组中最大的值就是我们要返回的LIS的长度*/

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n==0 || n==1) return n;
        vector<int> dp(n, 1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


/*下面来看一种优化时间复杂度到O(nlgn)的解法，这里用到了二分查找法，所以才能加快运行时间。思路是，我们先建立一个数组ends，
把首元素放进去，然后比较之后的元素，如果遍历到的新元素比ends数组中的首元素小的话，替换首元素为此新元素，如果遍历到的新元素
比ends数组中的末尾元素还大的话，将此新元素添加到ends数组末尾(注意不覆盖原末尾元素)。如果遍历到的新元素比ends数组首元素大，
比尾元素小时，此时用二分查找法找到第一个不小于此新元素的位置，覆盖掉位置的原来的数字，以此类推直至遍历完整个nums数组，此时
ends数组的长度就是我们要求的LIS的长度，注意的是ends数组的值可能不是一个真实的LIS，比如输入数组nums为{4, 2, 4，5，3，7}，
那么算完后的ends数组为{2，3，5，7}，可以发现它不是一个原数组的LIS，只是长度相等而已，千万要注意这点。*/
 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> ends {nums[0]};
        for (auto n : nums) {
            if (n < ends[0]) {
                ends[0] = n;
            } else if (n > ends.back()) {
                ends.push_back(n);
            } else {
                int left = 0;
                int right = ends.size();
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (ends[mid] < n) {
                        left = mid + 1;
                    } else right = mid;
                }
                ends[right] = n;
            }
        }
        return ends.size();
    }
};








