/*77. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

/*这道题让求1到n共n个数字里k个数的组合数的所有情况，还是要用深度优先搜索DFS来解，像这种要求出所有结果的集合，
一般都是用DFS调用递归来解。那么我们建立一个保存最终结果的大集合res，还要定义一个保存每一个组合的小集合solution，
每次放一个数到solution里，如果solution里数个数到了k个，则把solution保存到最终结果中，否则在下一层中继续调用递归。
https://blog.csdn.net/u010500263/article/details/18435495 */


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> solution;
        dfs(n, k, 1, solution, res);
        return res;
    }
    void dfs(int n, int k, int level, vector<int>& solution, vector<vector<int>>& res) {
        if (solution.size() == k){ 
            res.push_back(solution);
        }
        for (int i = level; i <= n; i++) {
            solution.push_back(i);
            dfs(n, k, i + 1, solution, res);
            solution.pop_back();
        }
    }
};












