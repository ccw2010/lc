/* 3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring,
"pwke" is a subsequence and not a substring.
*/

/* 下面这种解法使用了set，核心算法和上面的很类似，把出现过的字符都放入set中，遇到set中没有的字符就加入set中并更新
结果res，如果遇到重复的，则从左边开始删字符，直到删到重复的字符停止 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> t;
        int res = 0;
        int left = 0, right = 0;
        int n = s.size();
        while (right < n){
            if (!t.count(s[right])){
                t.insert(s[right++]);
                res = max(res, (int) t.size());
            } else {
                t.erase(s[left++]);
            }
        }
        return res;
    }
};






