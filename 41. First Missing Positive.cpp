/*41. First Missing Positive

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:
Input: [1,2,0] Output: 3

Example 2:
Input: [3,4,-1,1] Output: 2

Example 3:
Input: [7,8,9,11,12] Output: 1
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        int val = 0;
        unordered_set<int> s;
        for (int n : nums) {
            if (n > 0){ 
                s.insert(n);
                val = max(val, n);
            }
        }
        for (int i = 1; i <= val; i++) {
            if (!s.count(i)) return i;
        }
        return val + 1;
        
    }
};





