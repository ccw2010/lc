/*106. Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

For example, given
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n1 = inorder.size();
        int n2 = postorder.size();
        if (n1 != n2) return NULL;
        return build(inorder, 0, n1-1, postorder, 0, n2-1);
    }
    TreeNode* build(vector<int> &inorder, int iLeft, int iRight, vector<int> &postorder, int pLeft, int pRoot) {
        if (iLeft > iRight || pLeft > pRoot) return NULL;
        int rootVal = postorder[pRoot];
        int i = 0;
        for (i = iLeft; i <= iRight; i++) {
            if (inorder[i] == rootVal) break;
        }
        int iRoot = i;
        TreeNode *node = new TreeNode(rootVal);
        int leftLength = iRoot - iLeft;
        node->left = build(inorder, iLeft, iRoot - 1, postorder, pLeft, pLeft + leftLength - 1);
        node->right = build(inorder, iRoot + 1, iRight, postorder, pLeft + leftLength, pRoot - 1);
        return node;  
    }
};









