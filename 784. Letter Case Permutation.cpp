/*784. Letter Case Permutation
Given a string s, we can transform every letter individually to be lowercase or uppercase to 
create another string.  Return a list of all possible strings we could create.

Examples:
Input: s = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: s = "3z4"
Output: ["3z4", "3Z4"]

Input: s = "12345"
Output: ["12345"]
*/

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        dfs(s, res, 0);
        return res;
    }
    
    void dfs(string& s, vector<string>& res, int i){
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        if (islower(s[i])){
            dfs(s, res, i+1);
            s[i] = toupper(s[i]);
        } else if (isupper(s[i])){
            dfs(s, res, i+1);
            s[i] = tolower(s[i]);
        }
        dfs(s, res, i+1);
    }
};











