/*671. Second Minimum Node In a Binary Tree
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node 
in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is 
the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' 
value in the whole tree.
If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.

Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*这道题让我们找二叉树中的第二小的结点值，并且给该二叉树做了一些限制，比如对于任意一个结点，要么其没有子结点，
要么就同时有两个子结点，而且父结点值是子结点值中较小的那个，当然两个子结点值可以相等。那么可直接上暴力搜索，
根据该树的附加条件可知，根结点一定是最小的结点值first，那么我们只要找出第二小的值second即可，初始化为整型的最大值。
然后对根结点调用递归函数，将first和second当作参数传进去即可。在递归函数中，如果当前结点为空，直接返回，若当前结点
值不等于first，说明其肯定比first要大，然后我们看其是否比second小，小的话就更新second，然后对当前结点的左右子结点
分别调用递归函数即可*/

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int first = root->val;
        int second = INT_MAX;
        preorder(root, first, second);
        if (second == first || second == INT_MAX) return -1;
        else return second;
    }
    
    void preorder(TreeNode* node, int& first, int& second) {
        if (!node) return;
        if (node->val > first && node->val < second) {
            second = node->val;
        }
        preorder(node->left, first, second);
        preorder(node->right, first, second);
    }
};










