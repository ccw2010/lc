/* 7. Reverse Integer

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit 
signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your 
function returns 0 when the reversed integer overflows. */

/*翻转数字问题需要注意的就是溢出问题，看了许多网上的解法，由于之前的OJ没有对溢出进行测试，所以网上很多人
的解法没有处理溢出问题也能通过OJ。现在OJ更新了溢出测试，所以还是要考虑到。为什么会存在溢出问题呢，我们知道
int型的数值范围是 -2147483648～2147483647，那么如果要翻转 1000000009 这个在范围内的数得到 9000000001，
而翻转后的数就超过了范围。我最开始的想法是，用long型数据，远大于int型这样就不会出现溢出问题*/


class Solution {
public:
    int reverse(int x) {
        if(x==0) return 0;
        int sign = x > 0 ? 1: -1;
        x = abs(x);
        long res = 0;
        while (x > 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res > INT_MAX) return 0;
        return sign * res;
    }
};

/* 这种解法更加简洁，不需对x的正负进行处理 */
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x != 0){
            res = res * 10 + x % 10;
            x /= 10;
        }
        return (res > INT_MAX || res < INT_MIN)? 0 : res;
    }
};








