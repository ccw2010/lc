/* 395. Longest Substring with At Least K Repeating Characters

Find the length of the longest substring T of a given string (consists of lowercase letters only) such that 
every character in T appears no less than k times.

Example 1:
Input: s = "aaabb", k = 3
Output: 3
The longest substring is "aaa", as 'a' is repeated 3 times.

Example 2:
Input: s = "ababbc", k = 2
Output: 5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/


class Solution {
public:
    int longestSubstring(string s, int k) {
        int m[128] = {0};
        for (char c : s) m[c]++;
            
        int res = 0;
        int maxIdx = 0; 
        bool ok = true;
        string substr;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (m[s[i]] < k) {
                substr = s.substr(maxIdx, i-maxIdx);
                res = max(res, longestSubstring(substr, k));
                ok = false;
                maxIdx = i + 1;
            }
        }
        if (ok) return n;
        else {
            substr = s.substr(maxIdx, n-maxIdx);
            return max(res, longestSubstring(substr, k));
        }
    }
};








