/*90. Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/*这道子集合之二是 78.Subsets 的延伸，这次输入数组允许有重复项，其他条件都不变，只需要在之前那道题解法的基础上
稍加改动便可以做出来，我们先来看非递归解法，拿题目中的例子[1 2 2]来分析，根据之前 Subsets 子集合 里的分析可知，
当处理到第一个2时，此时的子集合为[], [1], [2], [1, 2]，而这时再处理第二个2时，如果在[]和[1]后直接加2会产生重复，
所以只能在上一个循环生成的后两个子集合后面加2，发现了这一点，题目就可以做了，我们用last来记录上一个处理的数字，然后
判定当前的数字和上面的是否相同，若不同，则循环还是从0到当前子集的个数，若相同，则新子集个数减去之前循环时子集的个数
当做起点来循环，这样就不会产生重复了。

整个添加的顺序为：

[]
[1]
[2]
[1 2]
[2 2]
[1 2 2]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        if (nums.empty()) return {};
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        int size = 1, last = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (last != nums[i]) {
                last = nums[i];
                size = res.size();
            }
            int newSize = res.size();
            for (int j = newSize - size; j < newSize; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

/*对于递归的解法，根据 78.Subsets 子集合里的构建树的方法，在处理到第二个2时，由于前面已经处理了一次2，
这次我们只在添加过2的[2] 和 [1 2]后面添加2，其他的都不添加，那么这样构成的二叉树如下图所示：

                        []        
                    /        \        
                  /            \     
                 /              \
              [1]                []
           /       \           /    \
          /         \         /      \        
       [1 2]       [1]       [2]     []
      /     \     /   \     /   \    / \
  [1 2 2] [1 2]  X   [1]  [2 2] [2] X  []


代码只需在原有的基础上增加一句话，while (nums[i] == nums[i + 1]) {i++}; 这句话的作用是跳过树中为X的叶节点，
因为它们是重复的子集，应被抛弃。*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        if (nums.empty()) return {};
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        getSubsets(nums, 0, subset, res);
        return res;
    }
    void getSubsets(vector<int> &nums, int pos, vector<int> &subset, vector<vector<int>> &res) {
        res.push_back(subset);
        int n = nums.size();
        for (int i = pos; i < n; i++) {
            subset.push_back(nums[i]);
            getSubsets(nums, i + 1, subset, res);
            subset.pop_back();
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                i++;
            }
        }
    }
};



















