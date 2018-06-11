/*745. Prefix and Suffix Search

Given many words, words[i] has weight i.

Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix). 
It will return the word with given prefix and suffix with maximum weight. If no word exists, return -1.

Examples:
Input:
WordFilter(["apple"])
WordFilter.f("a", "e") // returns 0
WordFilter.f("b", "") // returns -1

Note:
words has length in range [1, 15000].
For each test case, up to words.length queries WordFilter.f may be made.
words[i] has length in range [1, 10].
prefix, suffix have lengths in range [0, 10].
words[i] and prefix, suffix queries consist of lowercase letters only.*/

/*这道题给了我们一些单词，让我们通过输入单词的前缀和后缀来查找单词的位置。单词的位置就是其权重值，
如果给定的前后缀能对应到不只一个单词，那么返回最大的权重。首先，一个单词如果长度为n的话，那么其就有n个prefix，
比如对于单词apple，其prefix即为"a", "ap", "app", "appl", "apple"，同理，后缀也有n个。那么其组成的情况就有n^2个，
所以最简单的方法就是把这n^2个前后缀组成一个字符串，和当前权重建立映射。如果后面的单词有相同的前后缀，直接用后面的
大权重来覆盖之前的权重即可。为了将前后缀encode成一个字符串，我们可以在中间加上一个非字母字符，比如'/'，然后在查找
的时候，我们先拼出“prefix/suffix”字符串，直接去哈希map中找即可，这种解法的WordFilter函数时间复杂度为O(N*L^2)，其中N
是单词个数，L是单词长度。f函数时间复杂度为O(1)，空间复杂度为O(N*L^2)，适合需要大量查找的情况下使用*/

class WordFilter {
public:
    WordFilter(vector<string> words) {
        int n = words.size();
        for (int k = 0; k < n; k++) {
            int len = words[k].size();
            for (int i = 0; i <= len; i++) {
                for (int j = 0; j <= len; j++) {
                    m[words[k].substr(0,i) + "/" + words[k].substr(len-j)] = k;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        if (!m.count(prefix + "/" + suffix)) return -1;
        else return m[prefix + "/" + suffix];
    }

private:
    unordered_map<string, int> m;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */





