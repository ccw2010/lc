/*383. Ransom Note

Given an arbitrary ransom note string and another string containing letters from all the magazines,
write a function that will return true if the ransom note can be constructed from the magazines;
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note: You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

/* 非常简单的一道题，就是用哈希Map统计字符的个数 */


class Solution {
public:
    bool canConstruct(string note, string magz) {
        unordered_map<char, int> m;
        for (char c : magz) ++m[c];
        for (char c : note) {
            if (--m[c] < 0) return false;
        }
        return true;
    }
};







