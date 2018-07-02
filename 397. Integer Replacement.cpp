/*397. Integer Replacement
 
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
 
What is the minimum number of replacements needed for n to become 1?

Example 1:
Input: 8
Output: 3

Explanation:
8 -> 4 -> 2 -> 1
 
Example 2:
Input: 7
Output: 4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1 */
 
/*这道题给了我们一个整数n，然后让我们通过变换变为1，如果n是偶数，我们变为n/2，如果是奇数，我们可以变为n+1或n-1，
让我们求变为1的最少步骤。那么一看道题的要求，就会感觉应该用递归很合适，我们直接按照规则写出递归即可，注意由于有n+1
的操作，所以当n为INT_MAX的时候，就有可能溢出，所以我们可以先将n转为长整型，然后再进行运算*/
 
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n % 2 == 0) {
        	return 1 + integerReplacement(n / 2);
        } else {
            long n1 = (long) n + 1;
            long n2 = (long) n - 1;
            return 2 + min(integerReplacement(n1 / 2), integerReplacement(n2 / 2));
        }
    }
}; 










