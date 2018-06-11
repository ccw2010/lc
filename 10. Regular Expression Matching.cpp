/*10. Regular Expression Matching

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","a*") → true
isMatch("aaa","aa") → false
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true 
isMatch("mississippi", "mis*is*p*.") → true 
*/

/*这道求正则表达式匹配的题和那道 Wildcard Matching 通配符匹配的题很类似，不同点在于*的意义不同，
在之前那道题中，*表示可以代替任意个数的字符，而这道题中的*表示之前那个字符可以有0个，1个或是多个，
就是说，字符串a*b，可以表示b或是aaab，即a的个数任意，这道题的难度要相对之前那一道大一些，分的情况的要复杂一些，
需要用递归Recursion来解，大概思路如下：

- 若p为空，若s也为空，返回true，反之返回false

- 若p的长度为1，若s长度也为1，且相同或是p为'.'则返回true，反之返回false

- 若p的第二个字符不为*，若此时s为空返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配

- 若p的第二个字符为*，若s不为空且字符匹配，调用递归函数匹配s和去掉前两个字符的p，若匹配返回true，否则s去掉首字母

- 返回调用递归函数匹配s和去掉前两个字符的p的结果*/


class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        bool matchFirst = ( p[0] == s[0] || p[0] == '.');
        if (p.size() == 1 && s.size() == 1) {
            return matchFirst;
        }
        if (p[1] != '*') {
            if (s.empty()) return false;
            return matchFirst && isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && matchFirst) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
            matchFirst = (s[0] == p[0] || p[0] == '.');
        }
        return isMatch(s, p.substr(2));
    }
};


/* 我们也可以用DP来解，定义一个二维的DP数组，其中dp[i][j]表示s[0,i)和p[0,j)是否match，然后有下面三种情况：

1.  P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
2.  P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
3.  P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern
						                                  repeats for at least 1 times.
*/


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1 && p[j-1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};






