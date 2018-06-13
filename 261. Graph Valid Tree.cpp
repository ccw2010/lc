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
必须是连通图，而且不能有环，所以我们的焦点就变成了验证是否是连通图和是否含有环。我们首先用DFS来做，根据pair来
建立一个图的结构，用邻接链表来表示，还需要一个一位数组v来记录某个节点是否被访问过，然后我们用DFS来搜索节点0，
遍历的思想是，当DFS到某个节点，先看当前节点是否被访问过，如果已经被访问过，说明环存在，直接返回false，如果未
被访问过，我们现在将其状态标记为已访问过，然后我们到邻接链表里去找跟其相邻的节点继续递归遍历，注意我们还需要
一个变量pre来记录上一个节点，以免回到上一个节点，这样遍历结束后，我们就把和节点0相邻的节点都标记为true，然后
我们再看v里面是否还有没被访问过的节点，如果有，则说明图不是完全连通的，返回false，反之返回true*/


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        unordered_set<int> visited{{0}};
        queue<int> q{{0}};
        for (auto x : edges) {
            graph[x.first].insert(x.second);
            graph[x.second].insert(x.first);
        }
        while (!q.empty()) {
            int t = q.front(); 
            q.pop();
            for (auto x : graph[t]) {
                if (visited.count(x)) return false;
                visited.insert(x);
                q.push(x);
                graph[x].erase(t);
            }
        }
        return visited.size() == n;
    }
};












