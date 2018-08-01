/*415. Add Strings

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:
The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = nums1.size() - 1;
        int j = nums2.size() - 1;
        string res = "";
        int carry = 0;
        while (i>=0 || j>=0 || carry){
            int sum = carry;
            if (i >= 0) sum += (nums1[i--] - '0');
            if (j >= 0) sum += (nums2[j--] - '0');
            carry = sum / 10;
            res = to_string(sum % 10) + res;
        }
        return res;
    }
};






