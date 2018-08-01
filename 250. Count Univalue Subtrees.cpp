/* 250. Count Univalue Subtrees

Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

Example:
Input:  root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

Output: 4  */

/* 这道题让我们求相同值子树的个数，就是所有节点值都相同的子树的个数，之前有道Largest BST Subtree，感觉挺像的，都是关于子树的问题，
可以用递归来做，我们这样想，符合条件的相同值的字数肯定是有叶节点的，而且叶节点也都相同(注意单独的一个叶节点也被看做是一个相同值子树)，
那么我们可以从下往上check，采用后序遍历的顺序，左右根，我们还是递归调用函数，对于当前遍历到的节点，如果对其左右子节点分别递归调用函数，
返回均为true的话，那么说明当前节点的值和左右子树的值都相同，那么又多了一棵树，所以结果自增1，然后返回当前节点值和给定值(其父节点值)
是否相同，从而回归上一层递归调用 */

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
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        isUnival(root, -1, res);
        return res;
    }
    bool isUnival(TreeNode* root, int val, int& res) {
        if (!root) return true;
        bool leftUnival  = isUnival(root->left, root->val, res);
        bool rightUnival = isUnival(root->right, root->val, res);
        if (!leftUnival || !rightUnival) {
            return false;
        }
        res++;
        return root->val == val;
    }
};









