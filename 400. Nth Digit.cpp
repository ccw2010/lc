/*400. Nth Digit
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:
Input: 3
Output: 3

Example 2:
Input: 11
Output: 0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10

sequence 1 2 3 4 5 6 7 8 9 1 0 1 1 1 2 1 3 1 4 1 5 1 6
Nth digital 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23

I list sequence 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
blow the sequence is the Nth digital, like the 11th digital is 0, 12 is 1, 13 is 1, 14 is 1, 15 is 2, 16 
is 1, 17 is 3.........

Sot ehe regular is very oberviously now:
1-------9 9*1 = 9 digits
10-----99 90 *2 = 180 digits
100---999 900 * 3 = 2700 digits

Now, for example gave N = 1000, then 1000-9-180 = 811, it means the 811th digit local in [100, 999], 
and we know each number like 100 has three digit, so 811 / 3 = 270,

Then, we know the 270th number in [100, 999], is 270th + 100 (start from 100) = 370.
370 still has three digit, which one is the answer? 3, 7, 0
811 % 3 = 1, so the first one is the answer, so return 3.*/

/*这道题是说自然数序列看成一个长字符串，问我们第N位上的数字是什么。那么这道题的关键就是要找出第N位所在的数字，
然后可以把数字转为字符串，这样直接可以访问任何一位。那么我们首先来分析自然数序列和其位数的关系，前九个数都是1位的，
然后10到99总共90个数字都是两位的，100到999这900个数都是三位的，那么这就很有规律了，我们可以定义个变量count，初始化为9，
然后每次循环扩大10倍，再用一个变量len记录当前循环区间数字的位数，另外再需要一个变量start用来记录当前循环区间的第一个数字，
我们n每次循环都减去len*count (区间总位数)，当n落到某一个确定的区间里了，那么(diff-1)/len就是目标数字在该区间里的坐标，
加上start就是得到了目标数字，然后我们将目标数字start转为字符串，(diff-1)%len就是所要求的目标位，最后别忘了考虑int溢出问题，
干脆把所有变量都申请为长整型的好了*/

class Solution {
public:
    int findNthDigit(int n) {
        long len = 1; count = 9;
        int start = 1;
        while (n > len * count) {
            n -= len * count;
            ++len;
            count *= 10;
            start *= 10;
        }
        int diff = n;
        int num = start + (diff - 1) / len;
        string numstr = to_string(num);
        int i = (diff - 1) % len;
        return numstr[i] - '0';
    }
};








