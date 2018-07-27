/*145. Binary Tree Postorder Traversal

Given a binary tree, return the postorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]

Follow up: Recursive solution is trivial, could you do it iteratively? */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*后序遍历的顺序是左-右-根，而先序遍历的顺序是根-左-右，二者其实还是很相近的，我们可以先在先序遍历的方法上
做些小改动，使其遍历顺序变为根-右-左，然后翻转一下，就是左-右-根啦，翻转的方法是反向加入结果res，每次都在
结果res的开头加入结点值，而改变先序遍历的顺序就只要该遍历一下入栈顺序，先左后右，这样出栈处理的时候就是先右后左*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> s{{root}};
        while(!s.empty()){
            TreeNode *node = s.top(); 
            s.pop();
            res.insert(res.begin(), node->val);
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }
        return res;
    }
};

/* 在144.Preorder Traversal中的解法二也可以改动一下变成后序遍历，改动的思路跟上面的解法一样，都是先将先序遍历的
根-左-右顺序变为根-右-左，再翻转变为后序遍历的左-右-根，翻转还是改变结果res的加入顺序，然后把更新辅助结点p的左右
顺序换一下即可 */
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (!s.empty() || p) {
            if (p) {
                s.push(p);
                res.insert(res.begin(), p->val);
                p = p->right;
            } else {
                TreeNode *t = s.top(); s.pop();
                p = t->left;
            }
        }
        return res;
    }
};









