/*38. Count and Say
The count-and-say sequence is the sequence of integers with the first five terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth term of the count-and-say sequence.
Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1. Output: "1"

Example 2:
Input: 4. Output: "1211"
*/

/* 这道计数和读法问题还是第一次遇到，看似挺复杂，仔细一看，算法很简单，就是对于前一个数，
找出相同元素的个数，把个数和该元素存到新的string里 */

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string res = "1";
        while (n--) {
            string cur = "";
            int size = res.size();
            for (int i = 0; i < size; i++) {
                int count = 1;
                while (res[i] == res[i+1]) {
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};










