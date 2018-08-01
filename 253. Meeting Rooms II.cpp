/*253. Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times 
[[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2

Example 2:
Input: [[7,10],[2,4]]
Output: 1
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


/* 这道题是252.Meeting Rooms的拓展，252只让我们是否能参加所有的会，也就是看会议之间有没有时间冲突，而这道题让我们求
最少需要安排几个会议室，有时间冲突的肯定需要安排在不同的会议室。第一种方法是用两个一维数组来做，分别保存起始时间和结束时间，
然后各自排个序，我们定义结果变量res和结束时间指针endpos，然后我们开始遍历，如果当前起始时间小于结束时间指针的时间，则结果
自增1，反之结束时间指针自增1，这样我们可以找出重叠的时间段，从而安排新的会议室 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts, ends;
        
        for (auto &x : intervals) {
            starts.push_back(x.start);
            ends.push_back(x.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int res = 0, endpos = 0;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (starts[i] < ends[endpos]) res++;
            else endpos++;
        }
        return res;
    }
};


/*第二种方法是用TreeMap来做的，我们遍历时间区间，对于起始时间，映射值自增1，对于结束时间，映射值自减1，然后我们
定义结果变量res，和房间数rooms，我们遍历TreeMap，时间从小到大，房间数每次加上映射值，然后更新结果res，遇到起始
时间，映射是正数，则房间数会增加，如果一个时间是一个会议的结束时间，也是另一个会议的开始时间，则映射值先减
后加仍为0，并不用分配新的房间，而结束时间的映射值为负数更不会增加房间数*/

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for (auto &x : intervals) {
            m[x.start]++;
            m[x.end]--;
        }
        int rooms = 0, res = 0;
        for (auto &x : m) {
            rooms += x.second;
            res = max(res, rooms);
        }
        return res;
    }
};







