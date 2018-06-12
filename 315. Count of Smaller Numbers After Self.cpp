/*315. Count of Smaller Numbers After Self

You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:
Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/

/*这道题给定我们一个数组，让我们计算每个数字右边所有小于这个数字的个数，目测我们不能用brute force，那么为了提高运算效率，
首先可以使用用二分搜索法，思路是将给定数组从最后一个开始，用二分法插入到一个新的数组，这样新数组就是有序的，那么此时该数字
在新数组中的坐标就是原数组中其右边所有较小数字的个数*/

// Binary Search
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> t;
        vector<int> res(n);
        for (int i = n-1; i>=0; i--) {
            int left = 0, right = t.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (t[mid] >= nums[i]) right = mid;
                else left = mid + 1;
            }
            res[i] = right;
            t.insert(t.begin() + right, nums[i]);
        }
        return res;
    }
};







