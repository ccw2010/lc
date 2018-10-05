/* 783. Minimum Distance Between BST Nodes

Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the 
values of any two different nodes in the tree.

Example :
Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:
          4
        /   \
      2      6
     / \    
    1   3  
while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between 
node 3 and node 2.
*/

/*这道题给了我们一棵二叉搜索树，让我们求任意个节点值之间的最小绝对差。由于BST的左<根<右的性质可知，如果按照中序遍历
会得到一个有序数组，那么最小绝对差肯定在相邻的两个节点值之间产生。所以我们的做法就是对BST进行中序遍历，然后当前节点值
和之前节点值求绝对差并更新结果res。这道题跟 530.Minimum Absolute Difference in BST没有任何区别，解法完全可以共
用。方法很直接，通过中序遍历按顺序从小到大将所有的结点值都存入到一个数组中，然后就遍历这个数组，找相邻的两个的差值最小
的返回即可*/

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
    int minDiffInBST(TreeNode* root) {
        if (!root) return 0;
        int res = INT_MAX;
        vector<int> vals;
        inorder(root, vals);
        int n = vals.size();
        for (int i = 1; i < n; i++) {
            res = min(res, vals[i] - vals[i-1]);
        }
        return res;
    }
    void inorder(TreeNode *node, vector<int> &vals) {
        if (!node) return;
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }
};






