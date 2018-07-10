/*720. Longest Word in Dictionary

Given a list of strings words representing an English Dictionary, find the longest word in words 
that can be built one character at a time by other words in words. If there is more than one 
possible answer, return the longest word with the smallest lexicographical order.
If there is no answer, return the empty string.

Example 1:
Input: words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:
Input: words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary. 
However, "apple" is lexicographically smaller than "apply".*/

/*这道题给了我们一个字典，是个字符串数组，然后问我们从单个字符开始拼，最长能组成啥单词，注意中间生成的字符串也要
在字典中存在，而且当组成的单词长度相等时，返回字母顺序小的那个。其实我们只要给数组排个序，就可以使用贪婪算法来做了，
并不需要什么DFS或BFS这么复杂。首先建立一个空的哈希set，然后我们直接遍历排序后的字典，对于当前的单词，如果当前单词
长度为1，或者该单词去掉最后一个字母后在集合中存在，这也不难理解，长度为1，说明是起始单词，不需要的多余的判断，否则
的话就要判断其去掉最后一个字母后的单词是否在集合中存在，存在的话，才说明其中间单词都存在，因为此时是从短单词向长单
词遍历，只要符合要求的才会加入集合，所以一旦其去掉尾字母的单词存在的话，那么其之前所有的中间情况都会在集合中存在。
我们更新结果res时，要判断当前单词长度是否大于结果res的长度，因为排序过后，默认先更新的字母顺序小的单词，所有只有
当当前单词长度大，才更新结果res，之后别忘了把当前单词加入集合中*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        unordered_set<string> s;
        sort(words.begin(), words.end());
        for (string w : words) {
            if (w.size() == 1 || s.count(w.substr(0, w.size() - 1))) {
                res = (w.size() > res.size()) ? w : res;
                s.insert(w);
            }
        }
        return res; 
    }
};









