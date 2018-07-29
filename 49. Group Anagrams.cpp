/* 49. Group Anagrams

Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

The idea is to use an unordered_map to store those strings that are anagrams. We use the sorted string as 
the key and the string itself as the value. The strings are stored in a multiset since there may be duplicates. 
Moreover, multiset will sort them by default as we desire.

The code is as follows.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};







