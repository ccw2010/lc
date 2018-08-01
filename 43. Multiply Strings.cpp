/*
43. Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
also represented as a string.

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

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        // max (m + n) digits
        vector<int> product(m + n, 0);
        string result;

        // reverse for ease of calculation
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // digit i * digit j contributes to digit i + j
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                product[i + j] += (num1[i] - '0') * (num2[j] - '0');
                product[i + j + 1] += product[i + j] / 10;
                product[i + j] %= 10;
            }
        }

        // remove leading 0; keep last 0 if all 0
        int k = m + n - 1;
        while(k>0 && product[k]==0){ 
            k--;
        }
        for (; k >= 0; k--){
            result += to_string(product[k]);
        }
        return result;
    }
};







