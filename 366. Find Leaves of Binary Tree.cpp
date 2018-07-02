/*366. Find Leaves of Binary Tree

Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, 
repeat until the tree is empty.

Example:
Given binary tree

          1
         / \
        2   3
       / \     
      4   5    

Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:

          1
         / 
        2          

2. Now removing the leaf [2] would result in this tree:
          1          

3. Now removing the leaf [1] would result in the empty tree:
          []         

Returns [4, 5, 3], [2], [1]. */

/*这道题给了我们一个二叉树，让我们返回其每层的叶节点，就像剥洋葱一样，将这个二叉树一层一层剥掉，最后一个剥掉根节点。
那么题目中提示说要用DFS来做，思路是这样的，每一个节点从左子节点和右子节点分开走可以得到两个深度，由于成为叶节点的
条件是左右子节点都为空，所以我们取左右子节点中较大值加1为当前节点的深度值，知道了深度值就可以将节点值加入到结果res
中的正确位置了，求深度的方法我们可以参见Maximum Depth of Binary Tree中求最大深度的方法*/

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        find(root, res);
        return res;

    }
    int find(TreeNode *root, vector<vector<int>> &res) {
        if (!root) return 0;
        int depth = 1 + max(find(root->left, res), find(root->right, res));
        if (depth > res.size()) res.resize(depth);
        res[depth-1].push_back(root->val);
        return depth;
    }
};

/*下面这种DFS方法没有用计算深度的方法，而是使用了一层层剥离的方法，思路是遍历二叉树，找到叶节点，将其赋值为NULL，
然后加入leaves数组中，这样一层层剥洋葱般的就可以得到最终结果*/

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while (root) {
            vector<int> leaves;
            root = remove(root, leaves);
            res.push_back(leaves);
        }
        return res;
    }
    TreeNode* remove(TreeNode *node, vector<int> &leaves) {
        if (!node) return NULL;
        if (!node->left && !node->right) {
            leaves.push_back(node->val);
            return NULL;
        }
        node->left = remove(node->left, leaves);
        node->right = remove(node->right, leaves);
        return node;
    }
};







