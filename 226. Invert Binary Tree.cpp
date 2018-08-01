/*226. Invert a binary tree.

Invert a binary tree

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 这道题让我们左右翻转二叉树, 可以用递归和非递归两种方法来解。
先来看递归的方法，写法非常简洁，交换当前左右节点，并直接调用递归即可 */

class Solution {
public:
    TreeNode* invertTree(TreeNode *root) {
        if (!root) return NULL;
        TreeNode *temp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(temp);
        return root;
    }
};


/*非递归的方法跟二叉树的层序遍历一样，需要用queue来辅助，先把根节点排入队列中，然后从队中取出来，
交换其左右节点，如果存在则分别将左右节点在排入队列中，以此类推直到队列中木有节点了停止循环，返回root即可*/

class Solution {
public:
    TreeNode* invertTree(TreeNode *root) { 
        if (!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            TreeNode *temp = node->right;
            node->right = node->left;
            node->left = temp;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};






