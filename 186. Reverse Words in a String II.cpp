/* 186. Reverse Words in a String II

Given an input string , reverse the string word by word. 

Example:
Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]

Note: 
A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.

Follow up: Could you do it in-place without allocating extra space? */

/*这道题让我们翻转一个字符串中的单词，跟151.everse Words in a String没有区别，之前那道题就是用in-place的方法做的，
而这道题反而更简化了题目，因为不考虑首尾空格了和单词之间的多空格了，方法还是很简单，先把整个字符串翻转一遍，再把每个单词翻转一遍*/

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        for (int i = 0, j = 0; i < n; i = j + 1) {
            for (j = i; j < n && !isblank(s[j]); j++);
            reverse(s.begin()+i, s.begin()+j);
        }
    }
};







