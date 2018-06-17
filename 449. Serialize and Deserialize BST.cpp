/*449. Serialize and Deserialize BST

Serialization is the process of converting a data structure or object into a sequence of bits so that it 
can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed 
later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be 
serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms 
should be stateless. */

/*道题让我们对二叉搜索树序列化和去序列化，跟297.Serialize and Deserialize Binary Tree极其相似，虽然题目中说编码成的
字符串要尽可能的紧凑，但是我们并没有发现跟之前那题有何不同，也没有看到能够利用BST性质的方法，姑且就按照之前题目的解法来写*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize(iss);
        
    }
private:
    void serialize(TreeNode* root, ostringstream &oss){
        if(!root) oss << "# ";
        else{
            oss << root->val << " ";
            serialize(root->left, oss);
            serialize(root->right, oss);
        }
    }
    TreeNode* deserialize(istringstream &iss){
        string val = "";
        iss >> val;
        if (val=="#") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(iss);
        root->right = deserialize(iss);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));




