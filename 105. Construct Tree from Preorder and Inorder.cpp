/*105. Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

For example, given
preorder = [3,9,20,15,7]
inorder =  [9,3,15,20,7]

Return the following binary tree:
    3
   / \
  9  20
    /  \
   15   7
*/

/*这道题要求从中序和后序遍历的结果来重建原二叉树，我们知道中序的遍历顺序是左-根-右，后序的顺序是左-右-根，对于这种树的重建
一般都是采用递归来做，由于后序的顺序的最后一个肯定是根，所以原二叉树的根节点可以知道，题目中给了一个很关键的条件就是树中没有
相同元素，有了这个条件就可以在中序遍历中也定位出根节点的位置，并以根节点的位置将中序遍历拆分为左右两个部分，分别对其递归调用
原函数*/

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
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n1 = preorder.size();
        int n2 = inorder.size();
        return build(preorder, 0, n1-1, inorder, 0, n2-1);
    }
    TreeNode* build(vector<int> &preorder, int pRoot, int pRight, vector<int> &inorder, int iLeft, int iRight) {
        if (pRoot > pRight || iLeft > iRight) return NULL;
        int rootVal = preorder[pRoot];
        int i = 0;
        for (i = iLeft; i <= iRight; i++) {
            if (inorder[i] == rootVal) break;
        }
        int iRoot = i;
        TreeNode *node = new TreeNode(rootVal);
        int leftLength = iRoot - iLeft;
        node->left = build(preorder, pRoot + 1, pRoot + leftLength, inorder, iLeft, iRoot - 1);
        node->right = build(preorder, pRoot + leftLength + 1, pRight, inorder, iRoot + 1, iRight);
        return node;
    }
};










