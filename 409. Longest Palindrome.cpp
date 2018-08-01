/* 409. Longest Palindrome

Given a string which consists of lowercase or uppercase letters, find the length of the longest 
palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note: Assume the length of given string will not exceed 1,010.

Example:
Input: "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

/*这又是一道关于回文字符串的问题，LeetCode上关于回文串的题有十来道，也算一个比较重要的知识点。这道题给了我们一个字符串，
让我们找出可以组成的最长的回文串的长度，由于字符顺序可以打乱，所以问题就转化为了求偶数个字符的个数，我们了解回文串的都知道，
回文串主要有两种形式，一个是左右完全对称的，比如noon, 还有一种是以中间字符为中心，左右对称，比如bob，level等，那么我们
统计出来所有偶数个字符的出现总和，然后如果有奇数个字符的话，我们取取出其最大偶数，然后最后结果加1即可*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char c : s) m[c]++;
        int res = 0;
        bool odd = false;
        for (auto &x :m) {
            res += x.second;
            if (x.second & 1) {
                res--;
                odd = true;
            } 
        }
        return odd ? res + 1 : res;
    }
};


/*I count how many letters appear an odd number of times. Because we can use all letters, except for 
each odd-count letter we must leave one, except one of them we can use. */
/*最后这种方法利用到了STL中的count函数，就是找字符串中某个字符出现的个数，那么我们和1相与，就可以知道该个数是奇数
还是偶数了，返回的写法和上面那种方法相同*/

class Solution {
public:
    int longestPalindrome(string s) {
        int odds = 0;
        for (char c='A'; c<='z'; c++){
            odds += count(s.begin(), s.end(), c) & 1;
        }
        return s.size() - max(0, odds-1);
    }
};





