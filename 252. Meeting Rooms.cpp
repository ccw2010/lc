/*252. Meeting Rooms
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
determine if a person could attend all meetings.

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
    bool canAttendMeetings(vector<Interval>& intervals) {
        map<int, int> m;
        for(int i = 0; i < intervals.size(); ++i){
	    m[intervals[i].start] = intervals[i].end; 
	}
        /*in case [[8,11],[17,20],[17,20]]*/
	if(m.size() < intervals.size()) 
            return false; 
        
	int lastEnding = 0;
	for (map<int,int>::iterator it=m.begin(); it!=m.end(); it++){ 
            if(it->first < lastEnding) 
                return false;
            lastEnding = it->second;
        }
        return true;
        
    }
};
