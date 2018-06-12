/*207. Course Schedule

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

Note:
Hints:
1. This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering 
exists and therefore it will be impossible to take all courses.
2. There are several ways to represent a graph. For example, the input prerequisites is a graph represented by a list of edges. 
Is this graph representation appropriate?
3. Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
4. Topological sort could also be done via BFS.

*/

/* 这道课程清单的问题给了很多提示，第一条就告诉我们了这道题的本质就是在有向图中检测环。 LeetCode中关于图的题很少，
有向图的仅此一道，还有一道关于无向图的题是 Clone Graph 无向图的复制。图这种数据结构相比于树啊，链表啊什么的要更为复杂一些，
尤其是有向图，很麻烦。第二条提示是在讲如何来表示一个有向图，可以用边来表示，边是由两个端点组成的，用两个点来表示边。
第三第四条提示揭示了此题有两种解法，DFS和BFS都可以解此题。我们先来看BFS的解法，我们定义二维数组graph来表示这个有向图，
一位数组indegree来表示每个顶点的入度。我们开始先根据输入来建立这个有向图，并将入度数组也初始化好。然后我们定义一个queue变量，
将所有入度为0的点放入队列中，然后开始遍历队列，从graph里遍历其连接的点，每到达一个新节点，将其入度减一，如果此时该点入度为0，
则放入队列末尾。直到遍历完队列中所有的值，若此时还有节点的入度不为0，则说明环存在，返回false，反之则返回true */

class Solution {
public:
    bool canFinish(int n, vector<pair<int, int>>& prereq) {
        vector<vector<int> > graph(n, vector<int>(0));
        vector<int> indegree(n, 0);
        for (auto p : prereq) {
            graph[p.second].push_back(p.first);
            indegree[p.first]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int x : graph[t]) {
                indegree[x]--;
                if (indegree[x] == 0) q.push(x);
            }
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] != 0) return false;
        }
        return true;
    }
};

/* 下面来看DFS的解法，也需要建立有向图，还是用二维数组来建立，和BFS不同的是，我们像现在需要一个一维数组visited来记录访问状态，
这里有三种状态，0表示还未访问过，1表示已经访问了，-1表示有冲突。大体思路是，先建立好有向图，然后从第一个门课开始，找其可构成哪门课，
暂时将当前课程标记为已访问，然后对新得到的课程调用DFS递归，直到出现新的课程已经访问过了，则返回false，没有冲突的话返回true，
然后把标记为已访问的课程改为未访问。代码如下：
*/
 

class Solution {
public:
    bool canFinish(int n, vector<pair<int, int>>& prereq) {
        vector<vector<int> > graph(n, vector<int>(0));
        vector<int> visited(n, 0);
        for (auto p : prereq) {
            graph[p.second].push_back(p.first);
        }
        for (int i = 0; i < n; i++) {
            if (!canFinishDFS(graph, visited, i)) return false;
        }
        return true;
    }
    bool canFinishDFS(vector<vector<int>> &graph, vector<int> &visited, int i) {
        if (visited[i] == -1) return false;
        if (visited[i] == 1) return true;
        visited[i] = -1;
        for (int n : graph[i]) {
            if (!canFinishDFS(graph, visited, n)) return false;
        }
        visited[i] = 1;
        return true;
    }
};






