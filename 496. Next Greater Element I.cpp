/* 496. Next Greater Element I

You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset 
of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. 
If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
For 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
For 1 in the first array, the next greater number for it in the second array is 3.
For 2 in the first array, there is no next greater number for it in the second array, so output -1.

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
For 2 in the first array, the next greater number for it in the second array is 3.
For 4 in the first array, there is no next greater number for it in the second array, so output -1.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n2; i++) {
            m[nums2[i]] = i;
        }
        for (int i = 0; i < n1; i++) {
            res[i] = -1;
            int start = m[nums1[i]];
            for (int j = start + 1; j < n2; ++j) {
                if (nums2[j] > nums1[i]) {
                    res[i] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};







