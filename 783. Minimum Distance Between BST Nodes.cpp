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
和之前节点值求绝对差并更新结果res。这里需要注意的就是在处理第一个节点值时，由于其没有前节点，所以不能求绝对差。这里用
变量pre来表示前节点值，这里由于题目中说明了所以节点值不为负数，所以我们给pre初始化-1，这样我们就知道pre是否存在。
如果没有题目中的这个非负条件，那么就不能用int变量来，必须要用指针，通过来判断是否为指向空来判断前结点是否存在。
还好这里简化了问题，用-1就能搞定了，这里我们先来看中序遍历的递归写法*/

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
        int res = INT_MAX, pre = -1;
        inorder(root, pre, res);
        return res;
    }
    void inorder(TreeNode* root, int& pre, int& res) {
        if (!root) return;
        inorder(root->left, pre, res);
        if (pre != -1) 
            res = min(res, root->val - pre);
        pre = root->val;
        inorder(root->right, pre, res);
    }
};






