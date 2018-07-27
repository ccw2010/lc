/* 154. Find Minimum in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]). Find the minimum element.
The array may contain duplicates.

Example 1:
Input: [1,3,5] Output: 1

Example 2:
Input: [2,2,2,0,1] Output: 0

When num[mid] == num[right], we couldn't sure the position of minimum in mid's left or right, so 
just let upper bound reduce one.
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0;
        int right = num.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (num[mid] > num[right]) left = mid + 1;
            else if (num[mid] < num[right])  right = mid;
            else right--; // when num[mid] == num[right] 
        }
        return num[left];
    }
};










