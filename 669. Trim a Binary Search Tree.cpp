/*669. Trim a Binary Search Tree

Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all 
its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should 
return the new root of the trimmed binary search tree.

Example 1:
Input: 
    1
   / \
  0   2
L = 1, R = 2
Output: 
    1
      \
       2

Example 2:
Input: 
    3
   / \
  0   4
   \
    2
   /
  1
L = 1, R = 3
Output: 
      3
     / 
   2   
  /
 1
*/

/*这道题让我们修剪一棵二叉搜索树，给了个边界范围[L,R], 所有不在这个范围内的结点应该被移除掉，但是仍需要保留
二叉搜索树的性质，即左<根<右，有时候是小于等于。正确方法其实应该是在遍历的过程中就修改二叉树，移除不合题意的
结点。当然对于二叉树的题，十有八九都是要用递归来解的。首先判断如果root为空，那么直接返回空即可。然后就是要看
根结点是否在范围内，如果根结点值小于L，那么返回对其右子结点调用递归函数的值；如果根结点大于R，那么返回对其左
子结点调用递归函数的值。如果根结点在范围内，将其左子结点更新为对其左子结点调用递归函数的返回值，同样，将其右
子结点更新为对其右子结点调用递归函数的返回值。最后返回root即可*/

TreeNode* trimBST(TreeNode* root, int L, int R) {
    if(!root) return NULL;
    else if(root->val < L) return trimBST(root->right, L, R);
    else if(root->val > R) return trimBST(root->left, L, R);
    else {
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    } 
}







