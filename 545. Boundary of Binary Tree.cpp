/*545. Boundary of Binary Tree

Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. 
Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path 
from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself 
is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies 
to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree 
if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1
Input:
  1
   \
    2
   / \
  3   4

Ouput: [1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed 
right boundary. So order them in anti-clockwise without duplicates and we have [1,3,4,2].

Example 2
Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput: [1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
*/

/*这道题给了我们一棵二叉树，让我们以逆时针的顺序来输出树的边界，按顺序分别为左边界，叶结点和右边界。那么最直接的方法
就是分别按顺序求出左边界结点，叶结点，和右边界结点。那么如何求的，对于树的操作肯定是用递归最简洁啊，所以我们可以写分
别三个递归函数来分别求左边界结点，叶结点，和右边界结点。首先我们先要处理根结点的情况，当根结点没有左右子结点时，其也
是一个叶结点，那么我们一开始就将其加入结果res中，那么再计算叶结点的时候又会再加入一次，这样不对。所以我们判断如果根
结点至少有一个子结点，我们才提前将其加入结果res中。然后再来看求左边界结点的函数，如果当前结点不存在，或者没有子结点，
我们直接返回。否则就把当前结点值加入结果res中，然后看如果左子结点存在，就对其调用递归函数，反之如果左子结点不存在，
那么对右子结点调用递归函数。而对于求右边界结点的函数就反过来了，如果右子结点存在，就对其调用递归函数，反之如果右子结
点不存在，就对左子结点调用递归函数，注意在调用递归函数之后才将结点值加入结果res，因为我们是需要按逆时针的顺序输出。
最后就来看求叶结点的函数，没什么可说的，就是看没有子结点存在了就加入结果res，然后对左右子结点分别调用递归即可*/

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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        if (root->left || root->right) res.push_back(root->val);
        leftBoundary(root->left, res);
        leaves(root, res);
        rightBoundary(root->right, res);
        return res;
    }
    void leftBoundary(TreeNode* node, vector<int> &res) {
        if (!node || (!node->left && !node->right)) return;
        res.push_back(node->val);
        if (!node->left) leftBoundary(node->right, res);
        else leftBoundary(node->left, res);
    }
    void rightBoundary(TreeNode* node, vector<int> &res) {
        if (!node || (!node->left && !node->right)) return;
        if (!node->right) rightBoundary(node->left, res);
        else rightBoundary(node->right, res);
        res.push_back(node->val);
    }
    void leaves(TreeNode* node, vector<int> &res) {
        if (!node) return;
        if (!node->left && !node->right) {
            res.push_back(node->val);
        }
        leaves(node->left, res);
        leaves(node->right, res);
    }
};










