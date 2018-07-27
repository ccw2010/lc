/*151. Reverse Words in a String

Given an input string, reverse the string word by word.

Example:  
Input: "the sky is blue",
Output: "blue is sky the".

First reverse the whole string, then reverse each word. */


/* 这道题让我们翻转字符串中的单词，题目中给了特别说明，如果单词之间遇到多个空格，只能返回一个，
而且首尾不能有单词，并且对C语言程序员要求空间复杂度为O(1)，所以我们只能对原字符串s之间做修改，
而不能声明新的字符串。那么我们如何翻转字符串中的单词呢，我们的做法是，先整个字符串整体翻转一次，
然后再分别翻转每一个单词（或者先分别翻转每一个单词，然后再整个字符串整体翻转一次），此时就能得到
我们需要的结果了。那么这里我们需要定义一些变量来辅助我们解题，storeIndex表示当前存储到的位置，
n为字符串的长度。我们先给整个字符串反转一下，然后我们开始循环，遇到空格直接跳过，如果是非空格字符，
我们此时看storeIndex是否为0，为0的话表示第一个单词，不用增加空格；如果不为0，说明不是第一个单词，
需要在单词中间加一个空格，然后我们要找到下一个单词的结束位置我们用一个while循环来找下一个为空格的
位置，在此过程中继续覆盖原字符串，找到结束位置了，下面就来翻转这个单词，然后更新i为结尾位置，最后
遍历结束，我们剪裁原字符串到storeIndex位置，就可以得到我们需要的结果 */

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.erase(s.begin() + storeIndex, s.end());
    }
};





