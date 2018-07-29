/*541. Reverse String II
Given a string and an integer k, you need to reverse the first k characters for every 2k characters 
counting from the start of the string. If there are less than k characters left, reverse all of them. 
If there are less than 2k but greater than or equal to k characters, then reverse the first k characters 
and left the other as original.

Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000] */

/*这道题是之前那道题Reverse String的拓展，同样是翻转字符串，但是这里是每隔k隔字符，翻转k个字符，最后如果不够k个了的话，
剩几个就翻转几个。比较直接的方法就是先用n／k算出来原字符串s能分成几个长度为k的字符串，然后开始遍历这些字符串，遇到2的倍数
就翻转，翻转的时候注意考虑下是否已经到s末尾了*/

class Solution {
public:
     string reverseStr(string s, int k) {
        int n = s.size(), cnt = n / k;
        for (int i = 0; i <= cnt; ++i) {
            if (i % 2 == 0) {
                if (i * k + k < n) {
                    reverse(s.begin() + i * k, s.begin() + i * k + k);
                } else {
                    reverse(s.begin() + i * k, s.end());
                }
            }
        }
        return s;
     }
};







