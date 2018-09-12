/* 39. Combination Sum

Given a set of candidate numbers (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/


/* 这种结果要求返回所有符合要求解的题十有八九都是要利用到DFS，相类似的题目有113. Path Sum II，90. Subsets II，
46. Permutations，47. Permutations II，77. Combinations等，如果仔细研究这些题目发现都是需要另写一个递归函数，
这里我们新加入三个变量，begin 记录当前的递归到的下标，solution为一个解，res保存所有已经得到的解，每次调用新的递归
函数时，此时的target要减去当前数组的的数*/


/* c++ solution use DFS backtracking */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {  
        if (nums.empty()) return {};
        vector<vector<int>> res;
        vector<int> solution;
        sort(nums.begin(), nums.end());
        dfs(nums, target, res, solution, 0);
        return res;
    }

    void dfs(vector<int> &nums, int target, vector<vector<int>> &res, vector<int> &solution, int begin) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(solution);
            return;
        } 
        int n = nums.size();
        for (int i = begin; i < n && nums[i] <= target; i++) {
            solution.push_back(nums[i]);
            dfs(nums, target - nums[i], res, solution, i);
            solution.pop_back();
        }
    }
};










