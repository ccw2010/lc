/*164. Maximum Gap 求最大间距
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

遇到这类问题肯定先想到的是要给数组排序，但是题目要求是要线性的时间和空间，那么只能用桶排序或者基排序。
这里我用桶排序Bucket Sort来做，首先找出数组的最大值和最小值，然后要确定
每个桶的容量，即为 (最大值 - 最小值) / 数字个数 + 1，
确定桶的个数，即为 (最大值 - 最小值) / 桶的容量 + 1，

然后需要在每个桶中找出局部最大值和最小值，而最大间距的两个数不会在同一个桶中，而是一个桶的最小值和另一个桶的最大值之间的间距。
*/

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.empty()) return 0;
        int largest = INT_MIN;
        int smallest = INT_MAX;
        int len = nums.size();
        for (int n : nums) {
            largest = max(largest, n);
            smallest = min(smallest, n);
        }
        int bsize = (largest - smallest) / len + 1;
        int nbuckets = (largest - smallest) / bsize + 1;
        vector<int> bucket_min(nbuckets, INT_MAX);
        vector<int> bucket_max(nbuckets, INT_MIN);
        set<int> s;
        for (int n : nums) {
            int idx = (n - smallest) / bsize;
            bucket_min[idx] = min(bucket_min[idx], n);
            bucket_max[idx] = max(bucket_max[idx], n);
            s.insert(idx);
        }
        int pre = 0, res = 0;
        for (int i = 1; i < len; i++) {
            if (!s.count(i)) continue;
            res = max(res, bucket_min[i] - bucket_max[pre]);
            pre = i;
        }
        return res;
    }
};













