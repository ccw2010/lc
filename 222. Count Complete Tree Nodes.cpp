/*222. Count Complete Tree Nodes

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, 
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes 
inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
*/

/*通过定义，我们可以看出，完美二叉树一定是完全二叉树，而完全二叉树不一定是完美二叉树。
那么这道题给的完全二叉树就有可能是完美二叉树，若是完美二叉树，节点个数很好求，为2的h次方-1，h为该完美二叉树的高度。
这道题可以用递归和非递归两种方法来解。我们先来看递归的方法，思路是分别找出以当前节点为根节点的左子树和右子树的高度并对比，
如果相等，则说明是满二叉树，直接返回节点个数，如果不相等，则节点个数为左子树的节点个数加上右子树的节点个数再加1(根节点)，
其中左右子树节点个数的计算可以使用递归来计算*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int h1 = 0, h2 = 0;
        TreeNode *p1 = root, *p2 = root;
        while (p1) {
            h1++;
            p1 = p1->left;
        }
        while (p2) {
            h2++;
            p2 = p2->right;
        }
        if (h1 == h2) {
            return pow(2, h1) - 1;
        }else{
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};





