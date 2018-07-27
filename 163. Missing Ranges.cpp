/* 163. Missing Ranges

Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], 
return its missing ranges.

Example:
Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"] */

/* 这道题让我们求缺失区间，跟 228.Summary Ranges很类似，这道题让我们求缺失的空间，给了一个空间的范围[lower upper]，
缺失的范围需要在给定的空间范围内。我们首先将lower赋给left，然后开始遍历nums数组，如果i小于nums长度且当前数字小于等于upper，
我们让right等于当前数字，否则如果当i等于nums的长度时或者当前数字大于upper时，将right赋为upper+1。然后判断left和right的值，
若相同，left自增1，否则当right大于left时，说明缺失空间存在，我们看left和right是否差1，如果是，说明只缺失了一个数字，若不是，
则说明缺失了一个区间，我们分别加上数字或者区间即可 */


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int len = nums.size();
        long left = lower;
        long right;
        for (int i = 0; i <= len; i++) {
            if (i < len && nums[i] <= upper) right = (long) nums[i];
            else right = (long) upper + 1;  
            
            if (left == right) left++;
            else if (right > left) {
                if (right - left == 1) res.push_back(to_string(left));
                else res.push_back(to_string(left) + "->" + to_string(right-1));
                left = right + 1;
            }
        }
        return res;
    }
};









