/*270. Closest Binary Search Tree Value
Given a non-empty binary search tree and a target value, find the value in the BST that is closest
to the target.

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

/*我们可以利用二分搜索树的特点[左<根<右]来快速定位，由于根节点是中间值，我们在往下遍历时，根据目标值和根节点
的值大小关系来比较，如果目标值小于节点值，则我们应该找更小的值，于是我们到左子树去找，反之我们去右子树找*/

class Solution {
public:
    int closestValue(TreeNode* root, double k) {
        int res = root->val;
        while (root) {
            if (abs(root->val - k) <= abs(res-k)) {
                res = root->val;
            }
            if (k < root->val){
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return res;
    }
};



