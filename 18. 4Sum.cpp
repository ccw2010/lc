/* 18. 4Sum
Given an array nums of n integers and an integer target, are there elements a, b, c, and d 
in nums such that a + b + c + d = target? Find all unique quadruplets in the array which 
gives the sum of target.
Note: The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

/*LeetCode中关于数字之和还有几道 1.Two Sum，15. 3Sum，16. 3Sum Closest，整体思路都是一样的，
在这里为了避免重复项，我们使用了STL中的set，如果新加入的数在set中原本就存在的话，插入操作就会失败，这样能很好的避免
重复项的存在。此题的O(n^3)解法的思路跟3Sum 三数之和基本没啥区别，就是多加了一层for循环，其他的都一样*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n-3; i++) {
            for (int j = i+1; j < n-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1, right = n-1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> solution {nums[i], nums[j], nums[left], nums[right]};
                        res.insert(solution);
                        left++; right--;
                    } else if (sum < target) left++;
                    else right--;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());   
    }
};








