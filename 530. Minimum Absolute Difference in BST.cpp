/* 530. Minimum Absolute Difference in BST

Given a binary search tree with non-negative values, find the minimum absolute difference between 
values of any two nodes.

Example:

Input:
   1
    \
     3
    /
   2

Output: 1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).*/

/*这道题给了我们一棵二叉搜索树，让我们求任意个节点值之间的最小绝对差。由于BST的左<根<右的性质可知，如果按照中序遍历
会得到一个有序数组，那么最小绝对差肯定在相邻的两个节点值之间产生。所以我们的做法就是对BST进行中序遍历，然后当前节点值
和之前节点值求绝对差并更新结果res。这里需要注意的就是在处理第一个节点值时，由于其没有前节点，所以不能求绝对差。这里我
们用变量pre来表示前节点值，这里由于题目中说明了所以节点值不为负数，所以我们给pre初始化-1，这样我们就知道pre是否存在。
如果没有题目中的这个非负条件，那么就不能用int变量来，必须要用指针，通过来判断是否为指向空来判断前结点是否存在。还好这
里简化了问题，用-1就能搞定了*/

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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int pre = -1;
        inorder(root, pre, res);
        return res;
    }
    void inorder(TreeNode* node, int& pre, int& res){
        if (!node) return;
        inorder(node->left, pre, res);
        if (pre != -1) res = min(res, node->val - pre);
        pre = node->val;
        inorder(node->right, pre, res);
    }
};







