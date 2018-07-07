/* 653. Two Sum IV - Input is a BST
Given a Binary Search Tree and a target number, return true if there exist two elements
 in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9
Output: True

Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28
Output: False */

/*这道题又是一道2sum的变种题，只要是两数之和的题，一定要记得用哈希表来做，这道题只不过是把数组变成了一棵二叉树
而已，我们遍历二叉树就行，然后用一个哈希set，在递归函数函数中，如果node为空，返回false。如果k减去当前结点值在
哈希set中存在，直接返回true；否则就将当前结点值加入哈希set，然后对左右子结点分别调用递归函数并且或起来返回即可*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <unordered_set>
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        unordered_set<int> s;
        return find(root, k, s);
    }
    bool find(TreeNode* node, int k, std::unordered_set<int> &s){
        if(!node) return false; 
        if (s.count(k - node->val)) return true;
        s.insert(node->val);
        return find(node->left, k, s) || find(node->right, k, s);
    }
};


/* 我们也可以用层序遍历来做，这样就是迭代的写法了，但是利用哈希表的精髓还是没变的 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        unordered_set<int> s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
          TreeNode *t = q.front(); 
          q.pop();
          if (s.count(k - t->val)) return true;
          s.insert(t->val);
          if (t->left) q.push(t->left);
          if (t->right) q.push(t->right);
        }
        return false;
    }
};








