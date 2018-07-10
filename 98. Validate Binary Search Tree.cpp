/*98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

Input:
    2
   / \
  1   3
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.

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

/*这道验证BST有很多种解法，可以利用它本身的性质来做，即左<根<右，也可以通过利用中序遍历结果为有序数列来做，
下面我们先来看最简单的一种，就是利用其本身性质来做，初始化时带入系统最大值和最小值，在递归过程中换成它们自
己的节点值，用long代替int就是为了包括int的边界条件*/

// Recursion without inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode *root, long lower, long upper) {
        if (!root) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return isValid(root->left, lower, root->val) && isValid(root->right, root->val, upper);
    }
};


/*这题设定为左<根<右, 实际上简化了难度，因为一般的二叉搜索树是左<=根<右，这道题左<根<右，那么就可以用中序遍历来做。
因为如果不去掉左=根这个条件的话，那么下边两个数用中序遍历无法区分：

   20       20
   /           \
 20            20

它们的中序遍历结果都一样，但是左边的是BST，右边的不是BST。去掉等号的条件则相当于去掉了这种限制条件。下面我们来看
使用中序遍历来做，这种方法思路很直接，通过中序遍历将所有的节点值存到一个数组里，然后再来判断这个数组是不是有序的*/

// Recursion
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        vector<int> vals;
        inorder(root, vals);
        int n = vals.size();
        for (int i = 0; i < n-1; i++) {
            if (vals[i] >= vals[i+1])  return false;
        }
        return true;
    }
    void inorder(TreeNode *root, vector<int> &vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};

/*当然这道题也可以用非递归来做，需要用到栈，因为中序遍历可以非递归来实现，只要在其上面稍加改动便可*/
// Non-recursion with stack
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p = root;
        TreeNode *pre = NULL;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            TreeNode *t = s.top();
            s.pop();
            if (pre && t->val <= pre->val) return false;
            pre = t;
            p = t->right;
        }
        return true;
    }
};












