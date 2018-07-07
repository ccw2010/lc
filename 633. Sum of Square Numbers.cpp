/*633. Sum of Square Numbers

Given a non-negative integer c, your task is to decide whether there're two integers a and b 
such that a^2 + b^2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: 3
Output: False*/

/* 这道题让我们求一个数是否能由平方数之和组成，我们可以从c的平方根，注意即使c不是平方数，也会返回一个整型数。
然后我们判断如果i*i等于c，说明c就是个平方数，只要再凑个0，就是两个平方数之和，返回true；如果不等于的话，
那么算出差值c - i*i，如果这个差值也是平方数的话，返回true。遍历结束后返回false */

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = sqrt(c); i >= 0; --i) {
            if (i * i == c) return true;
            int d = c - i * i;
            int t = sqrt(d);
            if (t * t == d) return true;
        }
        return false;
    }
};



/* 下面这种方法用到了集合set，从0遍历到c的平方根，对于每个i*i，都加入集合set中，然后计算c - i*i，如果这个差值
也在集合set中，返回true，遍历结束返回false */

class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> s;
        for (int i = 0; i <= sqrt(c); ++i) {
            s.insert(i * i);
            if (s.count(c - i * i)) return true;
        }
        return false;
    }
};


/*下面这种解法比较高效，用a和b代表了左右两个范围，分别为0和c的平方根，然后while循环遍历，如果a*a + b*b刚好等于c，
那么返回true；如果小于c，则a增大1；反之如果大于c，则b自减1 */
 
class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0, b = sqrt(c);
        while (a <= b) {
        	int x = a * a + b * b;
            if ( x == c) return true;
            else if (x < c) a++;
            else b--;
        }
        return false;
    }
};








