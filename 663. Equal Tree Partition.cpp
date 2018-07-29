/* 663. Equal Tree Partition

Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to 
two trees which have the equal sum of values after removing exactly one edge on the original tree.

Example 1:
Input:     
    5
   / \
  10 10
    /  \
   2   3

Output: True

Explanation: 
    5
   / 
  10
Sum: 15

   10
  /  \
 2    3
Sum: 15

Example 2:
Input:     
    1
   / \
  2  10
    /  \
   2   20

Output: False
Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge 
on the tree.

Note:
The range of tree node value is in the range of [-100000, 100000].
1 <= n <= 10000 */

/*这道题让我们划分等价树，就是说当移除一条边后，被分成的两棵树的结点之和需要相等。通过题目中的例子我们可以发现，如果我们
将每个结点的结点值变成其所有子结点的结点值之和再加上当前的结点值，那么对于例子1来说，根结点的结点值就变成了30，断开位置的
结点就变成了15，那么我们就可以发现其实只要断开位置的结点值是根结点值的一半，就存在等价划分。所以这道题的难点就是更新每个结
点的结点值，我们可以使用递归来做。解题一开始使用的是unordered_set，把更新后的每个结点值都存入集合中，但是对于test case: 
[0, 1, -1] 会fail, 仔细分析下这个case，发现更新后的根结点值还是0，而且0已经被存入集合了，而0除以2还是0，在集合中存在，
会返回true，但其实这棵树是不能等价划分的。0的情况确实比较特殊，所以我们使用unordered_map，建立更新后的结点值和其出现次数
之间的映射，这样只有map中0的个数大于1的时候，才返回true。这样完美的避开了根结点为0的陷阱，Perfect */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>
class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int,int> m;
        int sum = traverse(root, m);
        if (sum == 0) return m[0] >= 2;
        return sum % 2 == 0 && m.count(sum / 2);
    }
    int traverse(TreeNode* node, unordered_map<int,int> &m) {
        if (!node) return 0;
        int cur = node->val + traverse(node->left, m) + traverse(node->right, m);
        m[cur]++;
        return cur;
    }
};








