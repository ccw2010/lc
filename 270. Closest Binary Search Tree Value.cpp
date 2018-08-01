/* 270. Closest Binary Search Tree Value

Given a non-empty binary search tree and a target value, find the value in the BST that is 
closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.

Example:
Input: root = [4,2,5,1,3], target = 3.714286
    4
   / \
  2   5
 / \
1   3
Output: 4
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
    int closestValue(TreeNode* root, double k) {
        int res = root->val;
        while (root) {
            int rval = root->val;
            if (abs(rval-k) <= abs(res-k)) {
                res = rval;
            }
            if (k < rval) root = root->left;
            else root = root->right;
        }
        return res;
    }
};






