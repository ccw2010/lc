/*Given two strings s and t which consist of only lowercase letters.
String t is generated by random shuffling string s and then add one more letter at a random position.
Find the letter that was added in t.

Example:
Input:
s = "abcd"
t = "abcde"

Output: e

Explanation:
'e' is the letter that was added.*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (char c : s) m[c]++;
        for (char c : t) {
            m[c]--;
            if (m[c] < 0) return c;
        }
        return 0;    
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char c : s) res ^= c;
        for (char c : t) res ^= c;
        return res;
    }
};
