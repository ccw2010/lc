/*229. Majority Element II

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Note: The algorithm should run in linear time and in O(1) space.

Example 1:
Input: [3,2,3]
Output: [3]

Example 2:
Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

/*The essential concepts is you keep a counter for the majority number X. If you find a number Y 
that is not X, the current counter should deduce 1. The reason is that if there is 5 X and 4 Y, 
there would be one (5-4) more X than Y. This could be explained as "4 X being paired out by 4 Y".

And since the requirement is finding the majority for more than ceiling of [n/3], the answer would 
be less than or equal to two numbers.
So we can modify the algorithm to maintain two counters for two majorities.

这道题让我们求出现次数大于n/3的众数，而且限定了时间和空间复杂度，那么就不能排序，也不能使用哈希表，
这么苛刻的限制条件只有一种方法能解了，那就是摩尔投票法 Moore Voting，这种方法在之前那道题Majority Element 
求众数中也使用了。题目中给了一条很重要的提示，让我们先考虑可能会有多少个众数，经过举了很多例子分析得出，任意一个
数组出现次数大于n/3的众数最多有两个，具体的证明我就不会了，我也不是数学专业的。那么有了这个信息，我们使用投票法
的核心是找出两个候选众数进行投票，需要两遍遍历，第一遍历找出两个候选众数，第二遍遍历重新投票验证这两个候选众数是
否为众数即可，选候选众数方法和前面那篇Majority Element 求众数一样，由于之前那题题目中限定了一定会有众数存在，
故而省略了验证候选众数的步骤，这道题却没有这种限定，即满足要求的众数可能不存在，所以要有验证*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int x = 0, y = 0;
        int count1 = 0, count2 = 0;
        for (auto &n : nums) {
            if (n == x) count1++;
            else if (n == y) count2++;
            else if (count1 == 0){ 
                x = n; count1++;
            }
            else if (count2 == 0) {
                y = n; count2++;
            }
            else{ 
                count1--; count2--;
            }
        }
        count1 = count2 = 0;
        for (auto &n : nums) {
            if (n == x) count1++;
            else if (n == y) count2++;
        }
        if (count1 > nums.size() / 3) res.push_back(x);
        if (count2 > nums.size() / 3) res.push_back(y);
        return res;
    }
};





