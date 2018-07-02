/* 386. Lexicographical Numbers 字典顺序的数字
 
Given an integer n, return 1 - n in lexicographical order.
For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/

/*这道题给了我们一个整数n，让我们把区间[1,n]的所有数字按照字典顺序来排列，题目中也给了我们字典顺序的例子。
那么我们需要重新排序，我最开始想到的方法是重写sort方法的comparator，把所有数字都转为字符串，然后两个字符串
按位相比，然后排好序后再转回数字，这种方法通过不了OJ的大集合，说明本题不是想考我们这种方法。论坛里看到大家
普遍使用的是下面这种方法，学习了一下，感觉思路十分巧妙，自己肯定想不出来。这种思路是按个位数遍历，在遍历下
一个个位数之前，先遍历十位数，十位数的高位为之前的个位数，只要这个多位数并没有超过n，就可以一直往后遍历，
如果超过了，我们除以10，然后再加1，如果加1后末尾形成了很多0，那么我们要用个while循环把0都去掉，然后继续运算 */


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; i++) {
            res[i] = cur;
            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                if (cur >= n) cur /= 10;
                cur += 1;
                while (cur % 10 == 0) cur /= 10;
            }
        }
        return res;
    }
};


/* Recursive solution
Just repeatedly try from 1 to 9, 1 -> 10 -> 100 first, and then plus 1 to the deepest number. 
Take 13 as example:
1 -> 10 -> (100) -> 11 -> (110) -> 12 -> (120) -> 13 -> (130) -> (14) -> 2 -> (20) ... -> 9 -> (90)*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        helper(1, n, res);
        return res;
    }
    
    void helper(int cur, int n, vector<int> &res) {
        if (cur > n) return;
        res.push_back(cur);
        helper(cur * 10, n, res);
        if (cur % 10 != 9) helper(cur+1, n, res);
    }
};





