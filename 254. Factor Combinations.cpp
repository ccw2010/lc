/*254. Factor Combinations

Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.

Write a function that takes an integer n and return all possible combinations of its factors.

Note:
You may assume that n is always positive.
Factors should be greater than 1 and less than n.

Example 1:
Input: 1
Output: []

Example 2:
Input: 37
Output:[]

Example 3:
Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]

Example 4:
Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

/*这道题给了我们一个正整数n，让我们写出所有的因子相乘的形式，而且规定了因子从小到大的顺序排列，那么对于这种
需要列出所有的情况的题目，通常都是用回溯法来求解的，由于题目中说明了1和n本身不能算其因子，那么我们可以从2开
始遍历到n，如果当前的数i可以被n整除，说明i是n的一个因子，我们将其存入一位数组solution中，然后递归调用n/i，
此时不从2开始遍历，而是从i遍历到n/i，停止的条件是当n等于1时，如果此时solution中有因子，我们将这个组合存入
结果res中 */

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> solution;
        backtrack(n, 2, solution, res);
        return res;
    }
    void backtrack(int q, int start, vector<int> &solution, vector<vector<int>> &res) {
        if (q == 1) {
            if (solution.size() > 1) res.push_back(solution);
        } else {
            for (int i = start; i <= q; i++) {
                if (q % i == 0) {
                    solution.push_back(i);
                    backtrack(q / i, i, solution, res);
                    solution.pop_back();
                }
            }
        }
    }
};






