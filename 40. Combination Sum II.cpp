/*40. Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique 
combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

*/

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int k) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        vector<int> solution;
        dfs(num, k, res, solution, 0);
        return res;
    }
    void dfs(vector<int> &num, int k, vector<vector<int> > &res, vector<int> &solution, int begin) {
        if (k < 0) return;
        else if (k == 0) res.push_back(solution);
        else {
            for (int i = begin; i < num.size(); i++) {
                if (i > begin && num[i] == num[i-1]) continue;
                solution.push_back(num[i]);
                dfs(num, k - num[i], res, solution, i + 1);
                solution.pop_back();
            }
        }
    }
};

















