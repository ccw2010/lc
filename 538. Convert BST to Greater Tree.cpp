/* 538. Convert BST to Greater Tree

Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key 
of the original BST is changed to the original key plus sum of all keys greater 
than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
*/

/*这道题让我们将二叉搜索树转为较大树，通过例子可以明白，是把每个结点值加上所有比它大的结点值总和当作新的结点值。
仔细观察题目中的例子可以发现，2变成了20，而20是所有结点之和，因为2是最小结点值，要加上其他所有结点值，所以肯定
就是所有结点值之和。5变成了18，是通过20减去2得来的，而13还是13，是由20减去7得来的，而7是2和5之和。开始想的方法
是先求出所有结点值之和，然后开始中序遍历数组，同时用变量sum来记录累加和，根据上面分析的规律来更新所有的数组。
但是通过看论坛，发现还有更巧妙的方法，不用先求出的所有的结点值之和，而是巧妙的将中序遍历左根右的顺序逆过来，变成
右根左的顺序，这样就可以反向计算累加和sum，同时更新结点值，叼的不行*/

// Solution: right->root->left traverse (iterative method)
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        int sum = 0;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p = p->right;
            }
            p = s.top(); 
            s.pop();
            p->val += sum;
            sum = p->val;
            p = p->left;
        }
        return root;
    }
};


/*同样的思路，或是用recursion的方法*/
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        traverse(root, sum);
        return root;
    }
    void traverse(TreeNode* node, int &sum) {
        if (!node) return;
        traverse(node->right, sum);
        node->val += sum;
        sum = node->val;
        traverse(node->left, sum);
    }
};





