/* 230. Kth Smallest Element in a BST

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
How would you optimize the kthSmallest routine?
*/

/*这又是一道关于BST的题，这道题给的提示是让我们用BST的性质来解题，最重要的性质是就是左<根<右，那么如果用中序遍历所有的节点
就会得到一个有序数组。所以解题的关键还是中序遍历啊。关于二叉树的中序遍历,先来看一种非递归的方法，中序遍历最先遍历到的是最小
的结点，那么我们只要用一个计数器，每遍历一个结点，计数器自增1，当计数器到达k时，返回当前结点值即可 */

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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); 
            s.pop();
            count++;
            if (count == k) return p->val;
            else p = p->right;
        }
        return 0;
    }
};

/* 当然，此题我们也可以用递归来解，还是利用中序遍历来解 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
    int dfs(TreeNode* root, int &k) {
        if (!root) return -1;
        int val = dfs(root->left, k);
        if (k == 0) return val;
        if (--k == 0) return root->val;
        return dfs(root->right, k);
    }
};

/* 再来看一种divide and conquer的思路，由于BST的性质，我们可以快速定位出第k小的元素是在左子树还是右子树，
我们首先计算出左子树的结点个数总和count，如果k小于等于左子树结点总和count，说明第k小的元素在左子树中，直接对左
子结点调用递归即可。如果k大于count+1，说明目标值在右子树中，对右子结点调用递归函数，注意此时的k应为k-count-1，
应为已经减少了count+1个结点。如果k正好等于count+1，说明当前结点即为所求，返回当前结点值即可 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int nLeft = countNodes(root->left);
        if (k <= nLeft) {
            return kthSmallest(root->left, k);
        } else if (k > nLeft + 1) {
            return kthSmallest(root->right, k - nLeft - 1);
        }
        return root->val;
    }

    int countNodes(TreeNode* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + count(node->right);
    }
};








