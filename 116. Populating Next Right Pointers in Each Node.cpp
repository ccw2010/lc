/*116. Populating Next Right Pointers in Each Node

Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, 
the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Note:
You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every 
  parent has two children).

Example:

Given the following perfect binary tree,

     1
   /  \
  2    3
 / \  / \
4  5  6  7

After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL */

/*这道题实际上是树的层序遍历的应用，既然是遍历，就有递归和非递归两种方法，最好两种方法都要会写。
下面先来看递归的解法，由于是完全二叉树，所以若节点的左子结点存在的话，其右子节点必定存在，
所以左子结点的next指针可以直接指向其右子节点，对于其右子节点的处理方法是，判断其父节点的next是否为空，
若不为空，则指向其next指针指向的节点的左子结点，若为空则指向NULL*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) {
            root->left->next = root->right;
        }
        if (root->right) {
            root->right->next = root->next? root->next->left : NULL;
        }
        connect(root->left);
        connect(root->right);
    }
};

/*对于非递归的解法要稍微复杂一点，需要用到queue来辅助，由于是层序遍历，每层的节点都按顺序加入queue中，
而每当从queue中取出一个元素时，将其next指针指向queue中下一个节点即可。*/

// Non-recursion, more than constant space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while (true) {
            TreeLinkNode *node = q.front();
            q.pop();
            if (node) {
                node->next = q.front();
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            } else {
                if (q.size() == 0 || q.front() == NULL) return;
                q.push(NULL);
            }
        }
    }
};









