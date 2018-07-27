/*189. Rotate Array

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> t = nums;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[(i + k) % n] = t[i];
        }
    }
};



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n==0 || (k %= n) == 0) return;  
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};









