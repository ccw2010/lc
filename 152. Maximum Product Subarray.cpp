/*152. Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at 
least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int res = nums[0], n = nums.size();
        int f[n], g[n];
        f[0] = g[0] = nums[0];
        for(int i=1; i<n; i++){
            int t = nums[i];
            f[i] = max(max(f[i-1]*t, g[i-1]*t), t);
            g[i] = min(min(f[i-1]*t, g[i-1]*t), t);
            res = max(res, f[i]);
        }
        return res;
    }  
};







