/*290. Word Pattern

Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern 
and a non-empty word in str.

Example 1:
Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:
Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:
Input: pattern = "abba", str = "dog dog dog dog"
Output: false */

/*这道题给我们一个模式字符串，又给我们一个单词字符串，让我们求单词字符串中单词出现的规律是否符合模式字符串中的规律。
那么首先想到就是用哈希表来做，可用两个哈希表来完成，分别将字符和单词都映射到当前的位置，那么我们在遇到新字符和单词时，
首先看两个哈希表是否至少有一个映射存在，如果有一个存在，则比较两个哈希表映射值是否相同，不同则返回false。如果两个表
都不存在映射，则同时添加两个映射
This solution read words on the fly*/

class Solution {
public:
    bool wordPattern(string pattern, string words) {
        map<char, int> m1;
        map<string, int> m2;
        istringstream in(words);
        int i = 0, n = pattern.size();
        for (string word; in >> word; i++) {
            char c = pattern[i];
            if (i == n || m1[c] != m2[word])
                return false;
            m1[c] = i + 1;
            m2[word] = i + 1;
        }
        return i == n;
    }
};





