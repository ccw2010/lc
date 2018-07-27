/* 139. Word Break 拆分词句
 
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated 
sequence of one or more dictionary words.

Note:
The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/

/* 这道拆分词句问题是看给定的词句能分被拆分成字典里面的内容，还是需要用动态规划Dynamic Programming来做

我们从题目中给的例子来分析：

l 

le e 

lee ee e 

leet 

leetc eetc etc tc c 

leetco eetco etco tco co o 

leetcod eetcod etcod tcod cod od d 

leetcode eetcode etcode tcode code 

T F F F T F F F T 

我们知道算法的核心思想是逐行扫描，每一行再逐个字符扫描，每次都在组合出一个新的字符串都要到字典里去找，如果有的话，
则跳过此行，继续扫描下一行。*/


class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        vector<bool> res(len + 1, false);
        res[0] = true;
        for (int i = 0; i < len + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (res[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    res[i] = true;
                    break;
                }
            }
        }
        return res[len];
    }
};






