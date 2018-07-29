/*211. Add and Search Word - Data structure design

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters 
a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
*/

/*这道题和 208.Implement Trie (Prefix Tree) 实现字典树(前缀树)类似，还是要用到字典树的结构，唯一不同的地方
就是search的函数需要重新写一下，因为这道题里面'.'可以代替任意字符，所以一旦有了'.'，就需要查找所有的子树，只要
有一个返回true，整个search函数就返回true，典型的DFS的问题，其他部分跟上一道实现字典树没有太大区别*/

class WordDictionary {
private:
    TrieNode *root;

public:   
    struct TrieNode {
        TrieNode *child[26];
        bool isWord;
        TrieNode() : isWord(false) {
            for (auto &n : child) n = NULL;
        }
    };
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &c : word){
            int i = c - 'a';
            if(!p->child[i]) {
                p->child[i] = new TrieNode();
            }
            p = p->child[i];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' 
    to represent any one letter. */
    bool search(string word) {
        return query(word, root, 0);
    }
    
    bool query(string &word, TrieNode *p, int i) {
        if (i == word.size()) return p->isWord;
        char c = word[i];
        if (c == '.') {
            for (auto &node : p->child) {
                if (node && query(word, node, i + 1)) return true;
            }
            return false;
        } else {
            return p->child[c-'a'] && query(word, p->child[c-'a'], i + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */










