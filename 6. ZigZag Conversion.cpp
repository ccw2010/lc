/*6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"

Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I       */

/* 这道题就是看坐标的变化。并且需要分块处理。

 n = 2 时，字符串坐标变成zigzag的走法就是：

 0 2 4 6

 1 3 5 7

 n = 3 时的走法是：

 0     4     8

 1  3  5  7  9

 2     6    10 


 n = 4 时的走法是：

 0      6        12

 1   5  7    11  13

 2  4   8  10    14

 3      9        15 

 
 可以发现规律，画红色的长度永远是 2n-2（想法是你试想把所有这些行压缩成两列，两边手挤一下，第二列永远的第一行和最后一行少字）。

 利用这个规律，可以按行填字，第一行和最后一行，就是按照2n-2的顺序一点点加的。

 其他行除了上面那个填字规则，就是还要处理斜着那条线的字，若i是行的index，j是列的index，则那条线的字的位置永远是 j + (2n-2) - 2i

 按照上面的规律就可以写出代码了。*/

class Solution {
public:
    string convert(string s, int n) {
        if(n <= 1) return s;
        string res;
        int len = 2 * n - 2;
        for (int i=0; i<n; i++){
            for(int j=i; j<s.size(); j+=len){
                res += s[j];
                int tmp = j + len - 2*i;
                if (i != 0 && i != n-1 && tmp < s.size()) {
                    res += s[tmp];
                }
            }
        }
        return res;
    }
};







