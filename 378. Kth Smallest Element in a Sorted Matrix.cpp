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


/* Binary search solution */
class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
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





