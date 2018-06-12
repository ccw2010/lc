/*Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.*/
 
/*这题核心点就在于使用哈希表映射. 用一个数组来代替哈希表，使用类似方法的题目有Minimum Window Substring 最小窗口子串，
Isomorphic Strings 同构字符串，Longest Substring Without Repeating Characters 最长无重复子串 和 1.1 Unique 
Characters of a String 字符串中不同的字符。然后把s中所有的字符出现个数统计起来，存入一个unordered_map中。
然后我们再来统计t字符串，如果发现不匹配则返回false*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for (char c : s) m[c]++;
        for (char c : t) m[c]--;
        
        for (char c : (s+t))
            if (m[c]) return false;
        return true;
    }
};

/* 简单粗暴，直接sort两个string，sort后相同则为anagram，否则不是。复杂度o(nlogn) */
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;  
    }
};



