/*724. Find Pivot Index
Given an array of integers nums, write a method that returns the "pivot" index of this array.
We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the 
sum of the numbers to the right of the index.
If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the 
left-most pivot index.

Example 1:
Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of 
index 3. Also, 3 is the first index where this occurs.

Example 2:
Input: 
nums = [1, 2, 3]
Output: -1
Explanation: 
There is no index that satisfies the conditions in the problem statement.
*/

/*这道题给了我们一个数组，让我们求一个中枢点，使得该位置左右两边的子数组之和相等。因为中枢点可能出现的位置就是数组上的位置，
所以我们搜索一遍就可以找出来，我们先求出数组的总和，然后维护一个当前数组之和curSum，然后对于遍历到的位置，用总和减去当前
数字，看得到的结果是否是curSum的两倍，是的话，那么当前位置就是中枢点，返回即可；否则就将当前数字加到curSum中继续遍历，
遍历结束后还没返回，说明没有中枢点，返回-1即可 */

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int cumsum = 0, n = nums.size();
        for (int i=0; i<n; i++){
            if (sum - nums[i] == 2 * cumsum) return i;
            cumsum += nums[i];
        }
        return -1;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.empty()) return -1;
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for (int i=1, j=n-2; i<n, j>=0; i++, j--){
            left[i] = left[i-1] + nums[i];
            right[j] = right[j+1] + nums[j];
        }
        for (int i=0; i<n; i++){
            if (left[i]==right[i]) return i;
        }
        return -1;
    }
};







