/* 67. Add Binary

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

*/

/*用了两个指针i,j分别指向a和b的末尾，然后每次取出一个字符，转为数字，若无法取出字符则按0处理，
然后定义进位carry，初始化为0，将三者加起来，对2取余即为当前位的数字，对2取商即为当前进位的值，
记得最后还要判断下carry，如果为1的话，要在结果最前面加上一个1*/

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int x = i >= 0 ? a[i--] - '0' : 0;
            int y = j >= 0 ? b[j--] - '0' : 0;
            int sum = x + y + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1) {
            if (i >= 0 ) c += a[i--] - '0';
            if (j >= 0 ) c += b[j--] - '0';
            res = to_string(c % 2) + res;
            c /= 2;
        }      
        return res;  
    }
};





