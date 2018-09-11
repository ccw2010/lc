/*261. Graph Valid Tree 
 
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to check whether these edges make up a valid tree.

For example:
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices 
are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] 
is the same as [1, 0] and thus will not appear together in edges. */


/*这道题给了我们一个无向图，让我们来判断其是否为一棵树，我们知道如果是树的话，所有的节点必须是连接的，也就是说
必须是连通图，而且不能有环，所以我们的焦点就变成了验证是否是连通图和是否含有环。我们来看BFS的解法，需要用queue
来辅助遍历，这里我们没有用一维向量来标记节点是否访问过，而是用了一个set，如果遍历到一个节点，在set中没有，则加入
set，如果已经存在，则返回false，还有就是在遍历邻接链表的时候，遍历完成后需要将节点删掉*/


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>> &edges) {
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        unordered_set<int> visited{0};
        queue<int> q;
        q.push(0);
        for (auto x : edges) {
            graph[x.first].insert(x.second);
            graph[x.second].insert(x.first);
        }
        while (!q.empty()) {
            int t = q.front(); 
            q.pop();
            for (auto nbr : graph[t]) {
                if (visited.count(nbr)) return false;
                visited.insert(nbr);
                q.push(nbr);
                graph[nbr].erase(t);
            }
        }
        return visited.size() == n;
    }
};


/*我们再来看Union Find的方法，这种方法对于解决连通图的问题很有效，思想是我们遍历节点，如果两个节点相连，
我们将其roots值连上，这样可以帮助我们找到环，我们初始化roots数组为-1，然后对于一个pair的两个节点分别调用
find函数，得到的值如果相同的话，则说明环存在，返回false，不同的话，我们将其roots值union上*/

// Union Find
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, -1);
        for (auto edge : edges) {
            int x = find(roots, edge.first);
            int y = find(roots, edge.second);
            if (x == y) return false;
            roots[x] = y;
        }
        return edges.size() == n - 1;
    }
    int find(vector<int> &roots, int i) {
        while (roots[i] != -1) i = roots[i];
        return i;
    }
};








