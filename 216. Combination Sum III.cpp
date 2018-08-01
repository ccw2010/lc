/*216. Combination Sum III

Find all possible combinations of k numbers that add up to a number n, given that only numbers 
from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:
All numbers will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

/*这道题是组合之和系列的第三道题，跟39,40都不太一样，那两道的联系比较紧密，变化不大，而这道跟它们最显著的不同就是这道题的个数
是固定的，为k。个人认为这道题跟77.Combinations更相似一些，但是那道题只是排序，对k个数字之和又没有要求。所以实际上这道题是它们
的综合体，两者杂糅到一起就是这道题的解法了，n是k个数字之和，如果n小于0，则直接返回，如果n正好等于0，而且此时out中数字的个数正好
为k，说明此时是一个正确解，将其存入结果res中 */

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> solution;
        dfs(k, n, 1, solution, res);
        return res;
    }
    void dfs(int k, int n, int level, vector<int> &solution, vector<vector<int> > &res) {
        if (n < 0) return;
        if (n == 0 && solution.size() == k) {
            res.push_back(solution);
        }
        for (int i = level; i <= 9; i++) {
            solution.push_back(i);
            dfs(k, n-i, i+1, solution, res);
            solution.pop_back();
        }
    }
};









