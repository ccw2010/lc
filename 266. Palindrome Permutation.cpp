/* 266. Palindrome Permutation

Given a string, determine if a permutation of the string could form a palindrome.

Example 1:
Input: "code"
Output: false

Example 2:
Input: "aab"
Output: true

Example 3:
Input: "carerac"
Output: true */


class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int count = 0;
        for (char c : s) m[c]++;
        for (auto it : m){
            if (it.second % 2) count++;
        }
        return count == 0 || (s.size() % 2 == 1 && count == 1);
    }
};


/* 解法二： 这种方法用到了一个set，我们遍历字符串，如果某个字母不在set中，我们加入这个字母，
   若字母已经存在，则删除该字母，那么最终如果set中没有字母或是只有一个字母时，说明是回文串 */

bool canPermutePalindrome(string s) {
    unordered_set<char> t;
    for (auto c : s) {
        if (!t.count(c)) t.insert(c);
        else t.erase(c);
    }
    return t.empty() || t.size() == 1;
}









