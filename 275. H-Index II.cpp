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


/* 这题是274.H-Index 求H指数的拓展，输入数组是有序的，让我们在O(log n)的时间内完成计算.
设数组长度为n，那么n-i就是引用次数大于等于citations[i]的文章数。如果citations[i]<n-i，说明i是有效的H-Index, 
如果一个数是H-Index，那么最大的H-Index一定在它后面（因为是升序的），根据这点就可以进行二分搜索了。*/


class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {  
            int mid = (left + right) / 2;
            if (citations[mid] == n - mid) {
                return n - mid;
            } else if (citations[mid] > n - mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
       return n - left;
    }
};








