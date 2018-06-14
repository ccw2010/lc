/*95. Unique Binary Search Trees II

Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

/*这道题是96.Unique Binary Search Trees的延伸，之前那个只要求算出所有不同的二叉搜索树的个数，这道题让把那些
二叉树都建立出来。这种建树问题一般来说都是用递归来解，这道题也不例外，划分左右子树，递归构造。*/

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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};
        return dfs(1, n);
    }
    vector<TreeNode*> dfs(int start, int end) {
        vector<TreeNode*> subTree;
        if (start > end) {
            subTree.push_back(NULL);
        }else {
            for (int i = start; i <= end; i++) {
                vector<TreeNode*> leftSubTree = dfs(start, i-1);
                vector<TreeNode*> rightSubTree = dfs(i+1, end);
                for (int j = 0; j < leftSubTree.size(); j++) {
                    for (int k = 0; k < rightSubTree.size(); k++) {
                        TreeNode *node = new TreeNode(i);
                        node->left = leftSubTree[j];
                        node->right = rightSubTree[k];
                        subTree.push_back(node);
                    }
                }
            }
        }
        return subTree;
    }
};

/*第一个版本有个严重的问题，上面的function存在大量的对象拷贝，因为所有变量都是在栈上开辟，
所以返回值的时候都需要通过拷贝构造函数来重构vector，面试中这个疏忽是不应该的。
修改版，这里应该用指针及堆来存储变量。若不用指针，全部实例化的话会存在大量的对象拷贝，要调用拷贝构造函数*/

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};
        return *dfs(1, n);
    }
    vector<TreeNode*>* dfs(int start, int end) {
        vector<TreeNode*> *subTree = new vector<TreeNode*>();
        if (start > end) {
            subTree->push_back(NULL);
        } else {
            for (int i = start; i <= end; i++) {
                vector<TreeNode*> *leftSubTree = dfs(start, i - 1);
                vector<TreeNode*> *rightSubTree = dfs(i + 1, end);
                for (int j = 0; j < leftSubTree->size(); ++j) {
                    for (int k = 0; k < rightSubTree->size(); ++k) {
                        TreeNode *node = new TreeNode(i);
                        node->left = (*leftSubTree)[j];
                        node->right = (*rightSubTree)[k];
                        subTree->push_back(node);
                    }
                }
            }
        }
        return subTree;
    }
};











