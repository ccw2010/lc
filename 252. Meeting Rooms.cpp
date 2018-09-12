/* 252. Meeting Rooms

Given an array of meeting time intervals consisting of start and end times 
[[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:
Input: [[0,30],[5,10],[15,20]]
Output: false

Example 2:
Input: [[7,10],[2,4]]
Output: true*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval> &intervals) {
        if (intervals.empty()) return true;
        map<int, int> m;
        for (const auto &x : intervals){
            m[x.start] = x.end; 
        }
        /*in case [[8,11],[17,20],[17,20]]*/
        if(m.size() < intervals.size()) return false; 
        
        int lastEnding = 0;
        for (const auto &x : m){ 
            if(x.first < lastEnding) return false;
            else lastEnding = x.second;
        }
        return true;      
    }
};


/*我们可以先给所有区间排个序，用起始时间的先后来排，然后我们从第二个区间开始，如果开始时间早于前一个区间的结束时间，
则说明会议时间有冲突，返回false，遍历完成后没有冲突，则返回true*/

bool compare(const Interval &a, const Interval &b){
    return a.start < b.start;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval> &intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size();
        for (int i = 1; i < n; i++) {
            if (intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }
        return true;
    }
};














