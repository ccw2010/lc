/*462. Minimum Moves to Equal Array Elements II 

Given a non-empty integer array, find the minimum number of moves required to make all array elements 
equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:
Input: [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 

这道题是453.Minimum Moves to Equal Array Elements的拓展，现在我们可以每次对任意一个数字加1或者减1，
让我们用最少的次数让数组所有值相等。那么这道题是否像上面一道题一样，有巧妙的方法呢？答案是肯定的。下面这
种解法实际上利用了之前296.Best Meeting Point的思想，我们首先给数组排序，那么我们最终需要变成的相等的
数字就是中间的数，如果数组有奇数个，那么就是最中间的那个数字；如果是偶数个，那么就是中间两个数的区间中的
任意一个数字。而两端的数字变成中间的一个数字需要的步数实际上就是两端数字的距离，讲到这里发现是不是就和
296.Best Meeting Point的思路是一样了。那么我们就两对两对的累加它们的差值就可以了 */
 

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0, j=n-1; i < j; i++, j--) {
            res += nums[j] - nums[i];
        }
        return res;
    }
};


/* 有了上面的分析，我们知道实际上最后相等的数字就是数组的最中间的那个数字，那么我们在给数组排序后，
直接利用坐标定位到中间的数字，然后算数组中每个数组与其的差的绝对值累加即可 */

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int mid = nums[nums.size() / 2];
        for (int num : nums) {
            res += abs(num - mid);
        }
        return res;
    }
};






