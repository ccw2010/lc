/* 504. Base 7
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"

Example 2:
Input: -7
Output: "-10" */

/*这道题给了我们一个数，让我们转为七进制的数，而且这个可正可负。那么我们想如果给一个十进制的100，怎么转为七进制。
我会先用100除以7，商14余2，然后用14除以7，商2余0，再用2除以7，商0余2，这样可以得到202。这种方法适合于代码实现，
要注意的是，我们要处理好负数的情况*/

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res = "";
        bool positive = num > 0;
        while (num != 0) {
            res = to_string(abs(num % 7)) + res;
            num /= 7;
        }
        return positive ? res : "-" + res;
    }
};

/*上面的思路也可以写成迭代方式，非常的简洁，仅要三行就搞定了*/
class Solution {
public:
    string convertToBase7(int n) {
        if (n < 0) 
            return "-" + convertToBase7(-n);
        else if (n < 7) 
            return to_string(n);
        else
            return convertToBase7(n/7) + to_string(n%7);
    }
};














