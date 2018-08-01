/*459. Repeated Substring Pattern
Given a non-empty string check if it can be constructed by taking a substring of it and appending 
multiple copies of the substring together. You may assume the given string consists of lowercase 
English letters only and its length will not exceed 10000.

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.

Example 2:
Input: "aba"
Output: False

Example 3:
Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)*/

/*这道题给了我们一个字符串，问其是否能拆成n个重复的子串。那么既然能拆分成多个子串，那么每个子串的长度肯定
不能大于原字符串长度的一半，那么我们可以从原字符串长度的一半遍历到1，如果当前长度能被总长度整除，说明可以分
成若干个子字符串，我们将这些子字符串拼接起来看跟原字符串是否相等。 如果拆完了都不相等，返回false*/


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if (n <= 1) return false;
        for (int i = n/2; i > 0; i--){
            if (n % i == 0){
                int c = n / i;
                string t = "";
                for (int j = 0; j<c; j++){
                    t += s.substr(0, i);
                }
                if (t==s) return true;
            }
        }
        return false;
    }
};






