/*392. Is Subsequence

Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long 
(length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence
 of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"
Return true.

Example 2:
s = "axc", t = "ahbgdc"
Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T 
has its subsequence. In this scenario, how would you change your code?*/


/*这道题我们可以用两个指针分别指向字符串s和t，然后如果字符相等，则i和j自增1，反之只有j自增1，最后看i是否等于s的长度，
等于说明s已经遍历完了，而且字符都有在t中出现过*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty()) return s.empty();
        int ns = s.size(), nt = t.size();
        if(ns > nt) return false;
        int i = 0, j = 0;
        while (i < ns && j < nt){
            if (s[i] == t[j]){
                j++; j++
            }else{
                j++;
            }
        }
        return i == ns;  
    }
};

/* 一开始觉得可以用hash table做，先统计t中每个字符的个数，再遍历s，遇到字符将其在hash table中的次数减一，当m[c]<0时，则为false，
遍历所有的字符后，则为true。可是遇到一下这种情况，即顺序颠倒后，这种解法仍然把它判断为true

Input: "acb"
"ahbgdc"
Output: true
Expected: false */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty()) return s.empty();
        if(s.size() > t.size()) return false;
        unordered_map<char, int> m;
        for (char c : t) m[c]++;
        for (char c : s){
            if (--m[c] <0 ) return false;
        }
        return true; 
    }
};

