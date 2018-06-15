/*378. Kth Smallest Element in a Sorted Matrix

Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
return 13.

Note: You may assume k is always valid, 1 ≤ k ≤ n2.*/


/*这道题让我们求有序矩阵中第K小的元素，这道题的难点在于数组并不是蛇形有序的，意思是当前行的最后一个元素并不一定会
小于下一行的首元素，所以我们并不能直接定位第K小的元素，所以只能另辟蹊径。先来看一种利用堆的方法，我们使用一个最大堆，
然后遍历数组每一个元素，将其加入堆，根据最大堆的性质，大的元素会排到最前面，我们把 -m[i][j] push到q中 */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        priority_queue<int> q;
        int row = m.size(), col = m[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                q.push(-m[i][j]);
            }
        }
        while(k-- > 1){
            q.pop();
        }
        return -q.top();
    }
};

/*这题我们也可以用二分查找法来做，我们由于是有序矩阵，那么左上角的数字一定是最小的，而右下角的数字一定是最大的，
所以这个是我们搜索的范围，然后我们算出中间数字mid，由于矩阵中不同行之间的元素并不是严格有序的，所以我们要在每一
行都查找一下mid，我们使用upper_bound，这个函数是查找第一个大于目标数的元素，如果目标数在比该行的尾元素大，则
upper_bound返回该行元素的个数，如果目标数比该行首元素小，则upper_bound返回0, 我们遍历完所有的行可以找出中
间数是第几小的数，然后k比较，进行二分查找，left和right最终会相等，并且会变成数组中第k小的数字。举个例子:

[1 2
12 100]

k = 3

那么刚开始left = 1, right = 100, mid = 50, 遍历完 count = 3，此时right更新为50
此时left = 1, right = 50, mid = 25, 遍历完之后 count = 3, 此时right更新为25
此时left = 1, right = 25, mid = 13, 遍历完之后 count = 3, 此时right更新为13
此时left = 1, right = 13, mid = 7, 遍历完之后 count = 2, 此时left更新为8
此时left = 8, right = 13, mid = 10, 遍历完之后 count = 2, 此时left更新为11
此时left = 11, right = 12, mid = 11, 遍历完之后 count = 2, 此时left更新为12
循环结束，left和right均为12，任意返回一个即可。

本解法的整体时间复杂度为O(nlgn*lgX)，其中X为最大值和最小值的差值*/

/* Binary search solution */
class Solution {
public:
    int kthSmallest(vector<vector<int>> &m, int k) {
        int left = m[0][0];
        int right = m.back().back();
        int row = m.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 0; i < row; i++) {
                count += upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();
            }
            if (count < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};


/* 上面的解法还可以进一步优化到O(nlgX)，其中X为最大值和最小值的差值，我们并不用对每一行都做二分搜索法，
我们注意到每列也是有序的，我们可以利用这个性质，从数组的左下角开始查找，如果比目标值小，我们就向右移一位，
而且我们知道当前列的当前位置的上面所有的数字都小于目标值，那么count += i+1，反之则向上移一位，这样我们也能
算出count的值。其余部分跟上面的方法相同 */
 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        int left = m[0][0];
        int right = m.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = search_less_equal(m, mid);
            if (count < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
   
    int search_less_equal(vector<vector<int>> &m, int target) {
        int n = m.size();
        int i = n - 1, j = 0;
        int res = 0;
        while (i >= 0 && j < n) {
            if (m[i][j] <= target) {
                res += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return res;
    }
};










