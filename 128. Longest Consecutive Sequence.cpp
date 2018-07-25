/* 128. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
Your algorithm should run in O(n) complexity.

Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.*/

/*这道题要求求最长连续序列，并给定了O(n)复杂度限制，我们的思路是，使用一个集合set存入所有的数字，然后遍历数组中的每个数字，
如果其在集合中存在，那么将其移除，然后分别用两个变量pre和next算出其前一个数跟后一个数，然后在集合中循环查找，如果pre在
集合中，那么将pre移除集合，然后pre再自减1，直至pre不在集合之中，对next采用同样的方法，那么next-pre-1就是当前数字的最
长连续序列，更新res即可。*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int n : nums) {
            if (!s.count(n)) continue;
            s.erase(n);
            int pre = n - 1, next = n + 1;
            while (s.count(pre)) {
                s.erase(pre);
                pre--;
            }
            while (s.count(next)) {
                s.erase(next);
                next++;
            }
            res = max(res, next - pre - 1);
        }
        return res;
    }
};

/*我们也可以采用哈希表来做，刚开始哈希表为空，然后遍历所有数字，如果该数字不在哈希表中，那么我们分别看其
左右两个数字是否在哈希表中，如果在，则返回其哈希表中映射值，若不在，则返回0，然后我们将left+right+1作为
当前数字的映射，并更新res结果，然后更新n-left和n-right的映射值*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (int n : nums) {
            if (!m.count(n)) {
                int left = m.count(n-1) ? m[n-1] : 0;
                int right = m.count(n+1) ? m[n+1] : 0;
                int sum = left + right + 1;
                m[n] = sum;
                res = max(res, sum);
                m[n-left] = sum;
                m[n+right] = sum;
            }
        }
        return res;
    }
};






