/* 257. Binary Tree Path
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree: 

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

*/

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root) return {};
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
    void dfs(TreeNode *root, string path, vector<string> &res) {
        path += to_string(root->val);
        if (!root->left && !root->right) res.push_back(path);
        else {
            if (root->left) dfs(root->left, path + "->", res);
            if (root->right) dfs(root->right, path + "->", res);
        }
    }
};





