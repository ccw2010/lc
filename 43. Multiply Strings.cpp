/* 43. Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/


/* 这道题让我们求两个字符串数字的相乘，输入的两个数和返回的数都是以字符串格式储存的，这样做的原因可能是
这样可以计算超大数相乘，可以不受int或long的数值范围的约束，那么我们该如何来计算乘法呢，小时候学过多位数
的乘法过程，都是每位相乘然后错位相加，那么这里就是用到这种方法，把错位相加后的结果保存到一个一维数组中，
然后分别每位上算进位，最后每个数字都变成一位，然后要做的是去除掉首位0，最后把每位上的数字按顺序保存到结果
中即可*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size(), n2 = num2.size();
        // max (n1 + n2) digits
        vector<int> product(n1 + n2, 0);

        // reverse for ease of calculation
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // digit i * digit j contributes to digit i + j
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                product[i + j] += (num1[i] - '0') * (num2[j] - '0');
                product[i + j + 1] += product[i + j] / 10;
                product[i + j] %= 10;
            }
        }

        // remove leading 0; keep last 0 if all 0
        int k = n1 + n2 - 1;
        while (k > 0 && product[k] == 0){ 
            k--;
        }

        string res;
        for (; k >= 0; k--){
            res += to_string(product[k]);
        }
        return res;
    }
};







