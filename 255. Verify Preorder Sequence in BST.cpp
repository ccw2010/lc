/*255. Verify Preorder Sequence in Binary Search Tree

Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Consider the following binary search tree: 

     5
    / \
   2   6
  / \
 1   3

Example 1:
Input: [5,2,6,1,3]
Output: false

Example 2:
Input: [5,2,1,3,6]
Output: true */

/*这道题让给了我们一个一维数组，让我们验证其是否为一个二叉搜索树的先序遍历出的顺序，我们都知道二叉搜索树的性质是左<根<右，
如果用中序遍历得到的结果就是有序数组，而先序遍历的结果就不是有序数组了，但是难道一点规律都没有了吗，其实规律还是有的，根据
二叉搜索树的性质，当前节点的值一定大于其左子树中任何一个节点值，而且其右子树中的任何一个节点值都不能小于当前节点值，那么我
们可以用这个性质来验证，举个例子，比如下面这棵二叉搜索树：
     5
    / \
   2   6
  / \
 1   3

其先序遍历的结果是{5, 2, 1, 3, 6}, 我们先设一个最小值low，然后遍历数组，如果当前值小于这个最小值low，返回false，对于根节点，
我们将其压入栈中，然后往后遍历，如果遇到的数字比栈顶元素小，说明是其左子树的点，继续压入栈中，直到遇到的数字比栈顶元素大，那么
就是右边的值了，我们需要找到是哪个节点的右子树，所以我们更新low值并删掉栈顶元素，然后继续和下一个栈顶元素比较，如果还是大于，
则继续更新low值和删掉栈顶，直到栈为空或者当前栈顶元素大于当前值停止，压入当前值，这样如果遍历完整个数组之前都没有返回false的话，
最后返回true即可 */

class Solution {
public:
    bool verifyPreorder(vector<int> &preorder) {
        int low = INT_MIN;
        stack<int> s;
        for (auto x : preorder) {
            if (x < low) return false;
            while (!s.empty() && x > s.top()) {
                low = s.top(); 
                s.pop();
            }
            s.push(x);
        }
        return true;
    }
};





