/*131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/


class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) return {};
        
        vector<vector<string>> res;
        vector<string> solution;
        dfs(s, 0, solution, res);
        return res;
    }
    
    void dfs(string& s, int start, vector<string>& solution, vector<vector<string> >& res) {
        if(start == s.size()) {
            res.push_back(solution);
            return;
        }
        for(int i=start; i < s.size(); i++) {
            if(isPalindrome(s, start, i)) {
                solution.push_back(s.substr(start, i-start+1));
                dfs(s, i+1, solution, res);
                solution.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int left, int right) {
        while(left <= right) {
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
};