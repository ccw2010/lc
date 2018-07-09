/* 687. Longest Univalue Path
Given a binary tree, find the length of the longest path where each node in the path has the same 
value. This path may or may not pass through the root.
Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:
Input:
              5
             / \
            4   5
           / \   \
          1   1   5

Output: 2

Example 2:
Input:
              1
             / \
            4   5
           / \   \
          4   4   5

Output: 2
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

/*这种解法使用了两个递归函数，使得写法简洁。首先还是先判断root是否为空，是的话返回0。
然后对左右子节点分别调用当前函数，取其中较大值保存到变量sub中，表示左右子树中最长的相同值路径，然后就是要跟
当前树的最长相同值路径比较，计算方法是对左右子结点调用一个path函数，并把当前结点值传进去，把返回值加起来和
sub比较，去较大值返回。在helper函数里，若当前结点为空，或者当前节点值不等于父结点值的话，返回0。否则结返回对
左右子结点分别调用helper递归函数中的较大值加1。这种写法跟求树的最大深度很像*/

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {        
        if (!root) return 0;
        int left = longestUnivaluePath(root->left);
        int right = longestUnivaluePath(root->right);
        int sub = max(left, right);
        return max(sub, path(root->left, root->val) + path(root->right, root->val));
    }
    int path(TreeNode* node, int k) {
        if (!node || node->val != k) return 0;
        return max(path(node->left, k), path(node->right, k)) + 1;
    }
};












