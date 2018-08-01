/*275. H-Index II

Given an array of citations sorted in ascending order (each citation is a non-negative integer) of 
a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers 
have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [0,1,3,5,6]
Output: 3 
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
             received 0, 1, 3, 5, 6 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.

Note:
If there are several possible values for h, the maximum one is taken as the h-index.

Follow up:
This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
Could you solve it in logarithmic time complexity?
*/

/*这题是274.H-Index 求H指数的拓展，输入数组是有序的，让我们在O(log n)的时间内完成计算，看到这个时间复杂度，应该敏锐的意识
到应该用二分查找法，我们最先初始化left和right为0和数组长度len-1，然后取中间值mid，用citations[mid]和len-mid做比较，如果
前者大，则right移到mid之前，反之right移到mid之后，终止条件是left>right，最后返回len-left即可*/


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (citations[mid] == n - mid){ 
            	return n - mid;
            }else if (citations[mid] > n - mid) {
            	right = mid - 1;
            }else left = mid + 1;
        }
        return n - left;
    }
};








