/*720. Longest Word in Dictionary

Given a list of strings words representing an English Dictionary, find the longest word in words 
that can be built one character at a time by other words in words. If there is more than one possible 
answer, return the longest word with the smallest lexicographical order.
If there is no answer, return the empty string.

Example 1:

Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:

Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. 
However, "apple" is lexicographically smaller than "apply".*/


class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        unordered_set<string> s;
        sort(words.begin(), words.end());
        for (string w : words) {
            if (w.size() == 1 || s.count(w.substr(0, w.size() - 1))) {
                res = (w.size() > res.size()) ? w : res;
                s.insert(w);
            }
        }
        return res;
        
    }
};