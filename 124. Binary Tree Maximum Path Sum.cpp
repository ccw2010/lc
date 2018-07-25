/*124. Binary Tree Maximum Path Sum

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in 
the tree along the parent-child connections. The path must contain at least one node and does not need 
to go through the root.

Example 1:
Input: [1,2,3]
       1
      / \
     2   3

Output: 6

Example 2:
Input: [-10,9,20,null,null,15,7]
   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/


class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* node, int& res) {
        if (!node) return 0;
        int left = dfs(node->left, res);
        left = max(left, 0);
        int right = dfs(node->right, res);
        right = max(right, 0);
        res = max(res, left + right + node->val);
        return max(left, right) + node->val;
    }
};





