/*547. Friend Circles

There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive 
in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect 
friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then 
the ith and jth students are direct friends with each other, otherwise not. And you have to output the total 
number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.

Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
*/

/*这道题让我们求朋友圈的个数，题目中对于朋友圈的定义是可以传递的，比如A和B是好友，B和C是好友，那么即使A和C不是好友，
那么他们三人也属于一个朋友圈。那么比较直接的解法就是DFS搜索，对于某个人，遍历其好友，然后再遍历其好友的好友，那么我
们就能把属于同一个朋友圈的人都遍历一遍，我们同时标记出已经遍历过的人，然后累积朋友圈的个数，再去对于没有遍历到的人在
找其朋友圈的人，这样就能求出个数。其实这道题的本质是323.Number of Connected Components in an Undirected Graph*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& m) {
        int n = m.size();
        if (n <= 1) return n;
        vector<bool> visited (n, false);
        int res = 0;
        for (int i = 0; i < n; i++){
            if (visited[i]) continue;
            dfs(m, i, visited);
            res++;
        }
        return res;
    }
    void dfs(vector<vector<int>> &m, int k, vector<bool> &visited){
        visited[k] = true;
        int n = m.size();
        for (int i = 0; i < n; i++){
            if (!m[k][i] || visited[i]) continue;
            dfs(m, i, visited);
        }
    }
};






