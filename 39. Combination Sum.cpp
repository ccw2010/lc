/*39. Combination Sum
Given a set of candidate numbers (candidates) (without duplicates) and a target number (k), 
find all unique combinations in candidates where the candidate numbers sums to k.

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

// c++ solution use DFS backtracking 
// Accepted 16ms c++ solution use backtracking for Combination Sum:
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        vector<int> solution;
        dfs(nums, k, res, solution, 0);
        return res;
    }

    void dfs(vector<int> &nums, int k, vector<vector<int>> &res, vector<int> &solution, int begin) {
        if (k<0){
            return;
        } else if (k==0) {
            res.push_back(solution);
        } else {
            for (int i = begin; i < nums.size() && nums[i]<=k; i++) {
                solution.push_back(nums[i]);
                dfs(nums, k - nums[i], res, solution, i);
                solution.pop_back();
            }
        }
    }
};