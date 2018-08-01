/* 560. Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays 
whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].*/

/*这道题给了我们一个数组，让我们求和为k的连续子数组的个数，看到这道题想着肯定要建立累加和数组啊，然后遍历累加和数组的
每个数字，首先看其是否为k，是的话结果res自增1，然后再加个往前的循环，这样可以快速求出所有的子数组之和，看是否为k */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums = nums;
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i-1] + nums[i];
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (sums[i] == k) res++;
            for (int j = i+1; j<n; j++) {
                if (sums[j] - sums[i] == k) res++;
            }
        }
        return res; 
    }
};

/*大家比较推崇的其实是这种解法，用一个哈希表来建立连续子数组之和跟其出现次数之间的映射，初始化要加入{0,1}这对映射，
这是为啥呢，因为我们的解题思路是遍历数组中的数字，用sum来记录到当前位置的累加和，我们建立哈希表的目的是为了让我们
可以快速的查找sum-k是否存在，即是否有连续子数组的和为sum-k，如果存在的话，那么和为k的子数组一定也存在，这样当sum
刚好为k的时候，那么数组从起始到当前位置的这段子数组的和就是k，满足题意，如果哈希表中事先没有m[0]项的话，这个符合题
意的结果就无法累加到结果res中，这就是初始化的用途*/

/*Solution 2. From solution 1, we know the key to solve this problem is sum[i, j]. 
So if we know sum[0, i-1] and sum[0, j], then we can easily get sum[i, j]. 
To achieve this, we just need to go through the array, calculate the current sum and save number of 
all seen PreSum to a HashMap. Time complexity O(n), Space complexity O(n).*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0, sum = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if(m.count(sum-k)) res += m[sum-k];
            m[sum]++; 
        }
        return res;
    }
};








