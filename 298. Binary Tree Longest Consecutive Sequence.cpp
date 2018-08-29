/* 298. Binary Tree Longest Consecutive Sequence 

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the 
parent-child connections. The longest consecutive path need to be from parent to child (cannot be the 
reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.

   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2. */


/*这道题让我们求二叉树的最长连续序列，关于二叉树的题基本都需要遍历树，而递归遍历写起来比较简单，下面这种解法是用到了
递归版的先序遍历，我们对于每个遍历到的节点，我们看节点值是否比参数值(父节点值)大1，如果是则长度加1，否则长度重置为1，
然后更新结果res，再递归调用左右子节点即可*/

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
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        preorder(root, root->val, 0, res);
        return res;
    }
    void dfs(TreeNode *root, int val, int count, int &res){
        if (!root) return;
        if (root->val == val+1) count++;
        else count=1;
        res = max(res, count);
        preorder(root->left, root->val, count, res);
        preorder(root->right, root->val, count, res);   
    }
};







