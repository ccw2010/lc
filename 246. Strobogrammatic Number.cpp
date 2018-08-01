/* 246. Strobogrammatic Number

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:
Input:  "69"
Output: true

Example 2:
Input:  "88"
Output: true

Example 3:
Input:  "962"
Output: false
*/


class Solution {
public:
    bool isStrobogrammatic(string num) {
        int i = 0, j = num.size() - 1;
        while (i <= j) {
            if (num[i] == num[j]) {
                if (num[i] != '1' && num[i] != '0' && num[i] != '8'){
                    return false;
                }
            } else {
                if ((num[i] != '6' || num[j] != '9') && (num[i] != '9' || num[j] != '6')) {
                    return false;
                }
            }
            i++; j--;
        }
        return true;
    }
};


class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m {{'0','0'}, {'1','1'}, {'8','8'}, {'6','9'}, {'9','6'}};
        int len = num.size();
        for (int i = 0; i <= len / 2; i++) {
            if (m[num[i]] != num[len-i-1]) return false;
        }
        return true;
    }
};







