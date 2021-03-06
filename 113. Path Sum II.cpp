/*113. Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, sum, path, res);
        return res;
    }
    void dfs(TreeNode *node, int sum, vector<int> &path, vector<vector<int>> &res) {
        if (!node) return;
        path.push_back(node->val);
        if (sum == node->val && !node->left && !node->right) {
            res.push_back(path);
        }
        dfs(node->left, sum - node->val, path, res);
        dfs(node->right, sum - node->val, path, res);
        path.pop_back();
    }
};











