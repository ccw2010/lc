/* 387. First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. 
If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2. */

/*用哈希表建立每个字符和其出现次数的映射，然后按顺序遍历字符串，找到第一个出现次数为1的字符，返回其位置即可*/

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size()==0) return -1;
        unordered_map<char,int> m;
        for (char c : s) m[c]++;
        for (int i=0; i<=s.size()-1; i++){
            if (m[s[i]]==1) return i;
        }
        return -1;
    }
};








