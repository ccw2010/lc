/*654. Maximum Binary Tree
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
*/

/*这道题给了我们一个数组，让我们创建一个最大二叉树，创建规则是数组中的最大值为根结点，然后分隔出的左右部分再分别
创建最大二叉树。这种题可上递归，首先就是要先找出数组中的最大值，由于数组是无序的，就直接遍历，找到了最大值，就创
建一个结点，然后将左右两个子数组提取出来，分别调用递归函数并将结果连到该结点上，最后将结点返回即可*/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return NULL;
        return dfs(nums, 0, nums.size()-1);
    }
    
    TreeNode* dfs(vector<int> &nums, int left,  int right){
        if(left>right) return NULL;
        int mid = left;
        for (int i=left+1; i<=right; i++){
            if(nums[i] > nums[mid]) mid = i;
        }
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = dfs(nums, left, mid-1);
        node->right = dfs(nums, mid+1, right);
        return node;
    }
};







