/*30. Substring with Concatenation of All Words

You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly 
once and without any intervening characters.

Example 1:
Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:
Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []
*/

/*道题让我们求串联所有单词的子串，给定一个长字符串，再给定几个长度相同的单词，让我们找出串联给定所有单词的子串的起始位置。
这道题我们需要用到两个哈希表，第一个哈希表先把所有的单词存进去，然后从开头开始一个个遍历，停止条件为当剩余字符个数小于单词
集里所有字符的长度。这时候我们需要定义第二个哈希表，然后每次找出给定单词长度的子串，看其是否在第一个哈希表里，如果没有，则
break，如果有，则加入第二个哈希表，但相同的词只能出现一次，如果多了，也break。如果正好匹配完给定单词集里所有的单词，则把i
存入结果中*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        vector<int> res;
        int n = words.size();
        int len = words[0].size();
        unordered_map<string, int> m1;
        for (const auto &w : words) {
            m1[w]++;
        }
        int size = s.size();
        for (int i = 0; i + n * len <= size; i++) {
            unordered_map<string, int> m2;
            int j = 0; 
            for (; j < n; j++) {
                string t = s.substr(i + j * len, len);
                if (!m1.count(t)) break;
                m2[t]++;
                if (m2[t] > m1[t]) break;
            }
            if (j==n) res.push_back(i);
        }
        return res;
    }
};





