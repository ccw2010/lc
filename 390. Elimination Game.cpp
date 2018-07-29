/*390. Elimination Game

There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number 
and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the right most number and 
every other number from the remaining numbers.
We keep repeating the steps again, alternating left to right and right to left, until a single number 
remains.

Find the last number that remains starting with a list of length n.

Example:
Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6
Output:
6*/


/* Detailed explanation:

Denote L as traversing [1,...,n] from left to right, 
	   R as traversing [1,...,n] from right to left.

    When n is odd:
    L(1234567) = R(246) = R(123)*2
    R(1234567) = L(246) = L(123)*2

    When n is even:
    L(123456) = R(246) = R(123)*2
    R(123456) = L(135) = L(123) + 1 (a bit tricky)
*/

class Solution {
public:
    int lastRemaining(int n) {
        return eliminate(n, true);    
    }
    
    int eliminate(int n, bool left2right) {
        if (n == 1) return 1;
        if (left2right) {
            return 2 * eliminate(n / 2, false);
        } else {
            return 2 * eliminate(n / 2, true) - 1 + n % 2;
        }
    }
};






