/*Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longestpath between any two nodes in a tree. 
This path may or may not pass through the root.

Example:
Given a binary tree 

          1
         / \
        2   3
       / \     
      4   5    
 

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
Note: The length of path between two nodes is represented by the number of edges between them.*/

/*Post-order traverse, 在深度的递归函数中顺便把直径算出*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /*这道题让我们求二叉树的直径，并告诉了我们直径就是两点之间的最远距离. 我们再来仔细观察例子中的那两个
 最长路径[4,2,1,3] 和 [5,2,1,3]，我们转换一种角度来看，是不是其实就是根结点1的左右两个子树的深度之和再加1呢。
 那么我们只要对每一个结点求出其左右子树深度之和，再加上1就可以更新结果res了。*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int res = 0;
        maxDepth(root, res);
        return res;
    }
    int maxDepth(TreeNode *node, int &res){
        if(!node) return 0;
        int left = maxDepth(node->left, res);
        int right = maxDepth(node->right, res);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};

/*为了减少重复计算，我们用哈希表建立每个结点和其深度之间的映射，这样某个结点的深度之前计算过了，
就不用再次计算了虽说不用进行优化也能通过OJ，但是毕竟还是优化一下好一点啊：*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int res = 0;
        unordered_map<TreeNode*, int> m;
        maxDepth(root, res, m);
        return res;
    }
    int maxDepth(TreeNode *node, int &res, unordered_map<TreeNode*, int> &m){
        if (!node) return 0;
        if (m.count(node)) return m[node];
        int left = maxDepth(node->left, res, m);
        int right = maxDepth(node->right, res, m);
        res = max(res, left + right);
        return m[node] = max(left, right) + 1;
    }
};






