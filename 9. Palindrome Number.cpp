/* 9. Palindrome Number

Determine whether an integer is a palindrome. Do this without extra space.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. 
Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:
Coud you solve it without converting the integer to a string?
*/


/*这道验证回文数字的题如果将数字转为字符串，就变成了验证回文字符串的题，没啥难度了，我们就直接来做follow up吧，
不能转为字符串，而是直接对整数进行操作，我们可以利用取整和取余来获得我们想要的数字，比如 1221 这个数字，如果 
计算 1221 / 1000， 则可得首位1， 如果 1221 % 10， 则可得到末尾1，进行比较，然后把中间的22取出继续比较 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int div = 1;
        while (x/div >=10){
            div *= 10;
        }
        while (x>0){
            int left = x/div;
            int right = x %10;
            if (left != right) return false;
            x = (x % div) /10;
            div /= 100;
        }
        return true;
    }
};


/*下面这种解法利用了如果x是palindrome，反转后仍是原数字，就不可能溢出，只要溢出一定不是palindrome返回false就行。
可以参考7.Reverse Integer这题, 直接调用reverse()。*/
 

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        return reverse(x) == x;
    }
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (res > INT_MAX / 10) return -1;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};












