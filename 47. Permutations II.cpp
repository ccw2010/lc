/*47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique 
permutations.

Example:
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]*/

/*在Permutations的基础上稍加修改，用set来保存结果，利用其不会有重复项的特点，然后再递归函数中的swap的地方，
判断如果i和start不相同，但是nums[i]和nums[start]相同的情况下跳过，继续下一个循环*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void permute(vector<int> &nums, int start, set<vector<int>> &res) {
        if (start >= nums.size()) res.insert(nums);
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};







