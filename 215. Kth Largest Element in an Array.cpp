/*215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element 
in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

/*这道题让我们求数组中第k大的数字，怎么求呢，当然首先想到的是给数组排序，然后求可以得到第k大的数字。
先看一种利用c++的STL中的集成的排序方法，不用我们自己实现，这样的话这道题只要两行就完事了*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

/*下面这种解法是利用了priority_queue的自动排序的特性，跟上面的解法思路上没有什么区别，
当然我们也可以换成multiset来做，一个道理，*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
};

/*上面两种方法虽然简洁，但是确不是本题真正想考察的东西。这道题最好的解法应该是下面这种做法，用到了快速排序
Quick Sort的思想，这里排序的方向是从大往小排。核心思想是每次都要先找一个中枢点Pivot，然后遍历其他所有的数字，
像这道题从大往小排的话，就把小于中枢点的数字放到左半边，把大于中枢点的放在右半边，这样中枢点是整个数组中第几大
的数字就确定了，虽然左右两部分不一定是完全有序的，但是并不影响本题要求的结果，所以我们求出中枢点的位置，如果正好
是k-1，那么直接返回该位置上的数字；如果大于k-1，说明要求的数字在左半部分，更新右边界，再求新的中枢点位置；
反之则更新右半部分，求中枢点的位置*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            else if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], i = left + 1, j = right;
        while (i <= j) {
            if (nums[i] < pivot && nums[j] > pivot) {
                swap(nums[i++], nums[j--]);
            }
            if (nums[i] >= pivot) i++;
            if (nums[j] <= pivot) j--;
        }
        swap(nums[left], nums[j]);
        return j;
    }
};




