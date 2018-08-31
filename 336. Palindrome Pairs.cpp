/*336. Palindrome Pairs

Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the 
concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]

Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/


/*这道题给我们了许多单词，让我们找出回文对，就是两个单词拼起来是个回文字符串，我最开始尝试的是brute force的方法，每两个单词
都拼接起来然后判断是否是回文字符串，但是超时，那么只能找别的方法来做。我们先来看第一种方法吧，要用到哈希表来建立每个单词和其
位置的映射，然后需要一个set来保存出现过的单词的长度，算法的思想是，遍历单词集，对于遍历到的单词，我们对其翻转一下，然后在哈希
表查找翻转后的字符串是否存在，注意不能和原字符串的坐标位置相同，因为有可能一个单词翻转后和原单词相等，现在我们只是处理了bat和
tab的情况，还存在abcd和cba，dcb和abcd这些情况需要考虑，这就是我们为啥需要用set，由于set是自动排序的，我们可以找到当前单词
长度在set中的iterator，然后从开头开始遍历set，遍历比当前单词小的长度，比如abcdd翻转后为ddcba，我们发现set中有长度为3的单词，
然后我们dd是否为回文串，若是，再看cba是否存在于哈希表，若存在，则说明abcdd和cba是回文对，存入结果中，对于dcb和aabcd这类的情况
也是同样处理，要在set里找的字符串要在遍历到的字符串的左边和右边分别尝试，看是否是回文对，这样遍历完单词集，就能得到所有的回文对*/


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        set<int> s;
        int i = 0;
        for (const string &w : words) {
            m[w] = i++;
            s.insert(w.size());
        }
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string t = words[i];
            int len = t.size();
            reverse(t.begin(), t.end());
            if (m.count(t) && m[t] != i) {
                res.push_back({i, m[t]});
            }
            for (auto it = s.begin(); it != s.find(len); it++) {
                int d = *it;
                if (valid(t, 0, len-d-1) && m.count(t.substr(len-d))) {
                    res.push_back({i, m[t.substr(len-d)]});
                }
                if (valid(t, d, len-1) && m.count(t.substr(0, d))) {
                    res.push_back({m[t.substr(0, d)], i});
                }
            }
        }
        return res;
    }
    
    bool valid(string t, int left, int right) {
        for (; left < right; left++, right--) {
            if (t[left] != t[right]) return false;
        }
        return true;
    }  
};










