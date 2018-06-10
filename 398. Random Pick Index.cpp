/* 398. Random Pick Index 
 
Given an array of integers with possible duplicates, randomly output the index of a given target number. 
You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. 
// Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);*/
 
/*这道题指明了我们不能用太多的空间，那么省空间的随机方法只有水塘抽样了，LeetCode之前有过两道需要用这种方法的题目
384.Shuffle an Array 和 382.Linked List Random Node。如果了解了水塘抽样，这道题就不算难题了，我们定义两个变量，
计数器count和返回结果res，我们遍历整个数组，如果数组的值不等于target，直接跳过；如果等于target，计数器加1，然后我们
在[0, count)范围内随机生成一个数字，如果这个数字是count的倍数，我们将res赋值为i即可 */

class Solution {
public:
    Solution(vector<int> nums)
        : v (nums) {
    }  
    int pick(int target) {
        int count = 0;
        int res = -1;
        int n = v.size();
        for (int i=0; i<n; i++){
            if (v[i] != target) continue;
            count++;
            if (rand() % count == 0) res = i;
        }
        return res;
    }
private:
    vector<int> v;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */




