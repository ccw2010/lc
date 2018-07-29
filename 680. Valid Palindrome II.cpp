/* 680. Valid Palindrome II
Given a non-empty string s, you may delete at most one character. Judge whether you can 
make it a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'. */

/*这道题是125.Valid Palindrome的拓展，还是让我们验证回复字符串，但是区别是这道题的字符串中只含有小写字母，
而且这道题允许删除一个字符，那么当遇到不匹配的时候，我们到底是删除左边的字符，还是右边的字符呢，我们的做法是
两种情况都要算一遍，只要有一种能返回true，那么结果就返回true。我们可以写一个子函数来判断字符串中的某一个范围
内的子字符串是否为回文串*/

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return isValid(s, i+1, j) || isValid(s, i, j-1);
            }
        }
        return true;
    }
    bool isValid(string s, int i, int j) {
        for (; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};










