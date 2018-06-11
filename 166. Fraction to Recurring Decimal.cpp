/*166. Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, 
return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 2, denominator = 3
Output: "0.(6)" */

/*这道题还是比较有意思的，可以写成分数的都是有理数，而有理数要么是有限的，要么是无限循环小数，无限不循环的叫无理数，
例如圆周率pi或自然数e等。由于还存在正负情况，处理方式是按正数处理，符号最后在判断，那么我们需要把除数和被除数取绝对值，
那么问题就来了：由于整型数INT的取值范围是-2147483648～2147483647，而对-2147483648取绝对值就会超出范围，所以我们需要
先转为long型再取绝对值。那怎么样找循环呢，肯定是再得到一个数字后要看看之前有没有出现这个数。为了节省搜索时间，我们采用
哈希表来存数每个小数位上的数字。还有一个小技巧，由于我们要算出小数每一位，采取的方法是每次把余数乘10，再除以除数，得到的
商即为小数的下一位数字。等到新算出来的数字在之前出现过，则在循环开始出加左括号，结束处加右括号。*/


class Solution {
public:
   string fractionToDecimal(int numerator, int denominator) {
        int sign1 = numerator >= 0 ? 1 : -1;
        int sign2 = denominator >= 0 ? 1 : -1;
        long num = abs((long) numerator );
        long den = abs((long) denominator );
        long quo = num / den;
        long rem = num % den;
        unordered_map<long , int> m;
        string res = to_string(quo);
        if (sign1 * sign2 == -1 && (quo > 0 || rem > 0)) {
            res = "-" + res;
        }
        if (rem == 0) return res;
        res += ".";
        string s = "";
        int pos = 0;
        while (rem != 0) {
            if (m.count(rem)) {
                s.insert(m[rem], "(");
                s += ")";
                return res + s;
            }
            m[rem] = pos;
            s += to_string((rem * 10) / den);
            rem = (rem * 10) % den;
            pos++;
        }
        return res + s;
        
    }
};













