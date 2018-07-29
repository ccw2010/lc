/*210. Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you 
should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish 
all courses, return an empty array.

Example 1:
Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .

Example 2:
Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .*/


/* 这题是207.Course Schedule的扩展，那道题只让我们判断是否能完成所有课程，即检测有向图中是否有环，而这道题要我们找出
要上的课程的顺序，即有向图的拓扑排序，此题正是基于之前解法的基础上稍加修改，我们从queue中每取出一个数组就将其存在结果中，
最终若有向图中有环，则结果中元素的个数不等于总课程数，那我们将结果清空即可 */             

class Solution {
public:
    vector<int> findOrder(int n, vector<pair<int, int>>& prereq) {
        vector<int> res;
        vector<vector<int>> graph(n, vector<int>(0));
        vector<int> indegree(n, 0);
        for (auto &p : prereq) {
            graph[p.second].push_back(p.first);
            indegree[p.first]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            res.push_back(t);
            q.pop();
            for (int &x : graph[t]) {
                indegree[x]--;
                if (indegree[x] == 0) q.push(x);
            }
        }
        if (res.size() != n) res.clear();
        return res;
    }
};






