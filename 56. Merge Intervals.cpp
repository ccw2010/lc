/* 56. Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
*/

/* 这道和57.Insert Interval很类似，这次题目要求我们合并区间，之前那题明确了输入区间集是有序的，
而这题没有，所以我们首先要做的就是给区间集排序，由于我们要排序的是个结构体，所以我们要定义自己的
compare，才能用sort来排序，我们以start的值从小到大来排序，排完序我们就可以开始合并了，首先把第
一个区间存入结果中，然后从第二个开始遍历区间集，如果结果中最后一个区间和遍历的当前区间无重叠，直
接将当前区间存入结果中，如果有重叠，将结果中最后一个区间的end值更新为结果中最后一个区间的end和
当前end值之中的较大值，然后继续遍历区间集，以此类推可以得到最终结果 */


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
*/

bool compare(const Interval &a, const Interval &b){
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res{intervals[0]};
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (res.back().end < intervals[i].start) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = max(res.back().end, intervals[i].end);
            }
        }   
        return res;
    }
};






