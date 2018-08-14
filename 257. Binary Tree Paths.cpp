/* 257. Binary Tree Path

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree: 

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"] */

/*这道题给我们一个二叉树，让我们返回所有根到叶节点的路径，跟113.Path Sum II很类似，比那道稍微简单一些，
不需要计算路径和，只需要返回所有的路径即可，那么思路还是用递归来解，树的题目，十有八九都是递归，而递归的
核心就是不停的DFS到叶结点，然后在回溯回去。在递归函数中，当我们遇到叶结点的时候，即没有左右子结点，那么
此时一条完整的路径已经形成了，我们加上当前的叶结点后存入结果res中，然后回溯。注意这里结果res需要用引用，
而path是不需要引用的，不然回溯回去还要删除新添加的结点，很麻烦。为了减少判断空结点的步骤，我们在调用递归
函数之前都检验一下非空即可*/

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
        if (root->left) dfs(root->left, path + "->", res);
        if (root->right) dfs(root->right, path + "->", res);
    }
};






