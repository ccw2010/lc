/*333. Largest BST Subtree

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:

    10
    / \
   5  15
  / \   \ 
 1   8   7

The Largest BST Subtree in this case is the highlighted one.
The return value is the subtree's size, which is 3.

Follow up:
Can you figure out ways to solve it with O(n) time complexity? */

/*这道题让我们求一棵Binary Tree的最大BST，所谓BST就是满足左<根<右的二分树，我们需要返回这个BST的节点个数。
题目中给的提示说我们可以用98.Validate Binary Search Tree的方法来做，时间复杂度为O(n2)，这种方法是把每个节点都当做根节点，
来验证其是否是二叉搜索数，并记录节点的个数，若是二叉搜索树，就更新最终结果*/

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        if (validBST(root, INT_MIN, INT_MAX)) {
            return countNodes(root);
        }else{
            return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
        }
    }
    bool validBST(TreeNode* root, int lower, int upper) {
        if (!root) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return validBST(root->left, lower, root->val) && validBST(root->right, root->val, upper);
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};






/*题目中的Follow up让我们用O(n)的时间复杂度来解决问题，我们还是采用DFS的思想来解题，由于时间复杂度的限制，只允许
我们遍历一次整个二叉树，由于满足题目要求的BST必定是有叶节点的，所以我们的思路就是先递归到最左子节点，然后逐层往上递归，
对于每一个节点，我们都记录当前最大的BST的节点数，当做为左子树的最大值，和做为右子树的最小值，当每次遇到左子节点不存在
或者当前节点值大于左子树的最大值，且右子树不存在或者当前节点值小于右子树的最小数时，说明BST的节点数又增加了一个，我们
更新结果及其参数，如果当前节点不是BST的节点，那么我们更新BST的节点数res为左右子节点的各自的BST的节点数的较大值*/
 

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0, mn = INT_MIN, mx = INT_MAX;
        bool d = isValidBST(root, mn, mx, res);
        return res;
    }
    bool isValidBST(TreeNode *root, int &mn, int &mx, int &res) {
        if (!root) return true;
        int left_n = 0, right_n = 0, left_mn = INT_MIN;
        int right_mn = INT_MIN, left_mx = INT_MAX, right_mx = INT_MAX;
        bool left = isValidBST(root->left, left_mn, left_mx, left_n);
        bool right = isValidBST(root->right, right_mn, right_mx, right_n);
        if (left && right) {
            if ((!root->left || root->val > left_mx) && (!root->right || root->val < right_mn)) {
                res = left_n + right_n + 1;
                mn = root->left ? left_mn : root->val;
                mx = root->right ? right_mx : root->val;
                return true;
            }
        }
        res = max(left_n, right_n);
        return false;
    }
};



