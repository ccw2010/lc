/*
103. Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, 
then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*Assuming after traversing the 1st level, nodes in queue are {9, 20, 8}, And we are going to traverse 
2nd level, which is even line and should print value from right to left [8, 20, 9].

We know there are 3 nodes in current queue, so the vector for this level in final result should be of size 3.
Then, queue [i] -> goes to -> vector[queue.size() - 1 - i]i.e. the ith node in current queue should be placed 
in (queue.size() - 1 - i) position in vector for that line.

For example, for node(9), it's index in queue is 0, so its index in vector should be (3-1-0) = 2.*/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        deque<TreeNode*> q;
        q.push_front(root);

        for (int k = 0; !q.empty(); k++) {
            res.push_back({});
            bool left2right = (k % 2 == 0);
            for (int i = q.size(); i > 0; i--) {
                TreeNode* node;
                if (left2right) {
                    node = q.front();
                    q.pop_front();
                    if (node->left) q.push_back(node->left);
                    if (node->right) q.push_back(node->right);
                } else {
                    node = q.back();
                    q.pop_back();
                    if (node->right) q.push_front(node->right);
                    if (node->left) q.push_front(node->left);
                }
                res[k].push_back(node->val);
            }
        }
        return res;
    }
};











