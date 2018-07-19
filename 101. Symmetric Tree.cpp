/* 101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3*/
   
/*判断二叉树是否是平衡树，比如有两个节点p, q，我们需要比较p的左子节点的值和q的右子节点的值是否相等，同时, 
还要比较p的右子节点的值和q的左子结点的值是否相等，以此类推比较完所有的左右两个节点*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root){
        if (!root) return true;
        return symmetric(root->left, root->right);
    }

    bool symmetric(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p==q;        
        if (p->val != q->val) return false;
        return symmetric(p->left, q->right) && symmetric(p->right, q->left);
    }    
};











