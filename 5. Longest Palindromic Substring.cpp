/*5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length 
of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
*/

/*此题可以用动态规划Dynamic Programming来解，根据132.Palindrome Partitioning II的解法很类似，
我们维护一个二维数组dp，其中dp[i][j]表示字符串区间[i,j]是否为回文串，当i = j时，只有一个字符，
肯定是回文串，如果i = j + 1，说明是相邻字符，此时需要判断s[i]是否等于s[j]，如果i和j不相邻，即
i-j >= 2时，除了判断s[i]和s[j]相等之外，dp[j+1][i-1]若为真，就是回文串，通过以上分析，可以写出递推式如下：

dp[i, j] = 1                                   if i == j

         = s[i] == s[j]                        if j = i + 1

         = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1      

这里有个有趣的现象就是如果我把下面的代码中的二维数组由int改为vector<vector<int>>后，就会超时，这说明int型
的二维数组访问执行速度完爆std的vector啊，所以以后尽可能的还是用最原始的数据类型吧。*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        int left = 0, right = 0, len = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < i; j++) {
                dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
                if (dp[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    left = j;
                    right = i;
                }
            }
            dp[i][i] = true;
        }
        return s.substr(left, right - left + 1);
    }
};









