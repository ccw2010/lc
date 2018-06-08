/*76. Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters 
in T in complexity O(n).

Example:
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/

/*这道题的要求是要在O(n)的时间度里实现找到这个最小窗口字串，那么暴力搜索Brute Force肯定是不能用的，
我们可以考虑哈希表，其中key是t中的字符，value是该字符出现的次数。

- 我们最开始先扫描一遍t，把对应的字符及其出现的次数存到哈希表中。

- 然后开始遍历s，遇到t中的字符，就把对应的哈希表中的value减一，直到包含了t中的所有的字符，纪录一个字串并更新最小字串值。

- 将子窗口的左边界向右移，略掉不在t中的字符，如果某个在t中的字符出现的次数大于哈希表中的value，则也可以跳过该字符*/


class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map<char, int> m;
        for (char c : t) {
             m[c]++;
        }
        int i = 0, count = 0;
        int minLen = s.size() + 1;
        string res = "";
        for (int j = 0; j < s.size(); j++) {
            if (m.count(s[j])) {
                m[s[j]]--;
                if (m[s[j]] >= 0) {
                    count++;
                }
                while (count == t.size()) {
                    if (j-i+1 < minLen) {
                        minLen = j - i + 1;
                        res = s.substr(i, minLen);
                    }
                    if (m.count(s[i])) {
                        m[s[i]]++;
                        if (m[s[i]] > 0) count--;
                    }
                    i++;
                }
            }
        }
        return res;  
    }
};











