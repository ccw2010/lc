/*297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it 
can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed 
later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/
deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string 
and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"

Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to 
follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms 
should be stateless.
*/

/*这道题让我们对二叉树进行序列化和去序列化的操作。序列化就是将一个数据结构或物体转化为一个位序列，可以存进一个文件或者内存缓冲器中，
然后通过网络连接在相同的或者另一个电脑环境中被还原，还原的过程叫做去序列化。现在让我们来序列化和去序列化一个二叉树，并给了我们例子。
这题有两种解法，分别为先序遍历的递归解法和层序遍历的非递归解法。先来看先序遍历的递归解法，非常的简单易懂，我们需要接入输入和输出
字符串流istringstream和ostringstream，对于序列化，我们从根节点开始，如果节点存在，则将值存入输出字符串流，然后分别对其左右子节点
递归调用序列化函数即可。对于去序列化，我们先读入第一个字符，以此生成一个根节点，然后再对根节点的左右子节点递归调用去序列化函数即可*/


// Recursion
class Codec {
private:
    void serialize(TreeNode *root, ostringstream &out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }
    TreeNode* deserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "#") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
};















