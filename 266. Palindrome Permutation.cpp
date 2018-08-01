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








