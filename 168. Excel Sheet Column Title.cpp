/* 168. Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...

Example 1:
Input: 1
Output: "A"

Example 2:
Input: 28
Output: "AB"

Example 3:
Input: 701
Output: "ZY"
*/

/*原理: 一位一位的求，此题从低位往高位求，每进一位，则把原数缩小26倍，再对26取余，之后减去余数，
再缩小26倍，以此类推，可以求出各个位置上的字母。最后只需将整个字符串翻转一下即可*/

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n--) {
            res += n % 26 + 'A';
            n /= 26;
        }
        reverse(res.begin(), res.end()); 
        return res;
    }
};




