/*762. Prime Number of Set Bits in Binary Representation

Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set 
bits in their binary representation. The number of set bits an integer has is the number of 1s present when written 
in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.

Example 1:
Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)

Example 2:
Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime) */

/*这道题给了我们一个整数范围[L, R]，让我们统计其中有多个整数，其二进制表示中非零位个数为质数。暴力搜索，
遍历整数范围[L, R]中的每一个数字，然后先统计出所有非零位个数count，通过和1相与，再右移一位的方式。
然后判断这个count是否是质数，判断的方法就是就是从其平方开始，一个一个的除，如果一直到2都没有约数，
那么就是质数，结果res累加1*/

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; i++) {
            int t = i;
            int count = 0;
            while (t > 0) {
                if (t&1 == 1) count++;
                t >>= 1;
            }
            if (isPrime(count) && count != 1) res++;
        }
        return res; 
    }
    
    bool isPrime(int n){
        for (int i = sqrt(n); i > 1; i--) {
            if (n % i == 0) return false;
        }
        return true;
    }
};









