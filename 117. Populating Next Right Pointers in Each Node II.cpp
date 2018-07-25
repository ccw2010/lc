/* 117. Populating Next Right Pointers in Each Node II 
 
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?

Note: You may only use constant extra space.
 
For example, given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
 */

/*这是116.Populating Next Right Pointers in Each Node 每个节点的右向指针的延续，原本的完全二叉树的条件不再满足，
但是整体的思路还是很相似，仍然有递归和非递归的解法。我们先来看递归的解法，这里由于子树有可能残缺，故需要平行扫描父节点
同层的节点，找到他们的左右子节点。*/

// Recursion, more than constant space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *p = root->next;
        while (p) {
            if (p->left) {
                p = p->left;
                break;
            }
            if (p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) root->right->next = p; 
        if (root->left) root->left->next = root->right ? root->right : p; 
        connect(root->right);
        connect(root->left);
    }
};

 
/*对于非递归的方法，之前的方法直接就能用，完全不需要做任何修改，每个节点的右向指针，代码如下：*/
// Non-recursion, more than constant space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeLinkNode *t = q.front(); q.pop();
                if (i < len - 1) t->next = q.front();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
    }
};

/*虽然以上的两种方法都能通过OJ，但其实它们都不符合题目的要求，题目说只能使用constant space，可OJ却没有写专门检测
space使用情况的test，那么下面贴上constant space的解法，这个解法也是用的层序遍历，只不过没有使用queue了，我们
建立一个dummy结点来指向每层的首结点的前一个结点，然后指针t用来遍历这一层，我们实际上是遍历一层，然后连下一层的next，
首先从根结点开始，如果左子结点存在，那么t的next连上左子结点，然后t指向其next指针；如果root的右子结点存在，那么t的
next连上右子结点，然后t指向其next指针。此时root的左右子结点都连上了，此时root向右平移一位，指向其next指针，如果
此时root不存在了，说明当前层已经遍历完了，我们重置t为dummy结点，root此时为dummy->next，即下一层的首结点，然后
dummy的next指针清空 */

// Non-recursion, constant space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *dummy = new TreeLinkNode(0), *t = dummy;
        while (root) {
            if (root->left) {
                t->next = root->left;
                t = t->next;
            }
            if (root->right) {
                t->next = root->right;
                t = t->next;
            }
            root = root->next;
            if (!root) {
                t = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
    }
};










