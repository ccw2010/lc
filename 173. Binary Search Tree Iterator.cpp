/*173. Binary Search Tree Iterator
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root 
node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height 
of the tree. */

/*这道题主要是二叉树的中序遍历的非递归形式，需要额外定义一个栈来辅助，二叉搜索树的建树规则就是 左 < 根 < 右，
用 Inorder 中序遍历即可从小到大取出所有节点*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root){
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = s.top();
        s.pop();
        int res = node->val;
        if(node->right){
            node = node->right;
            while (node) {
                s.push(node);
                node = node->left;
            }
        }
        return res;
    }
    
private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */