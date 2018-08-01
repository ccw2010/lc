/* 485. Max Consecutive Ones

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3

Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, count = 0;
        for (int n : nums) {
            count = (count + 1) * n;
            res = max(res, count);
        }
        return res;   
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, count = 0;
        for (int n : nums) {
            count = (n == 0) ? 0 : count + 1;
            res = max(res, count);
        }
        return res;
    }
};






