/* 169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that 
appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2
*/

/* Moore voting */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, count = 0;
        for (int n : nums) {
            if (count == 0) {
                res = n; 
                count++;
            }
            else if (n == res) count++;
            else count--;
        }
        return res;
    }
};







