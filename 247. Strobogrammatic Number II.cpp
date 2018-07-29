/* 247. Strobogrammatic Number II

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

Example:
Input:  n = 2
Output: ["11","69","88","96"]
*/

/* 这道题让我们找出长度为n的所有的对称数，题目中提示说可以用递归来做，而且提示了递归调用n-2，而不是n-1。
我们先来列举一下n为0,1,2,3,4的情况：

n = 0:   none

n = 1:   0, 1, 8

n = 2:   11, 69, 88, 96

n = 3:   101, 609, 808, 906, 111, 619, 818, 916, 181, 689, 888, 986

n = 4:   1001, 6009, 8008, 9006, 1111, 6119, 8118, 9116, 1691, 6699, 8698, 9696, 1881, 6889, 8888, 9886, 
1961, 6969, 8968, 9966

我们注意观察n=0和n=2，可以发现后者是在前者的基础上，每个数字的左右增加了[1 1], [6 9], [8 8], [9 6]，看n=1和n=3更加明显，
在0的左右增加[1 1]，变成了101, 在0的左右增加[6 9]，变成了609, 在0的左右增加[8 8]，变成了808, 在0的左右增加[9 6]，变成
了906, 然后在分别在1和8的左右两边加那四组数，我们实际上是从m=0层开始，一层一层往上加的，需要注意的是当加到了n层的时候，左右
两边不能加[0 0]，因为0不能出现在两位数及多位数的开头，在中间递归的过程中，需要有在数字左右两边各加上0的那种情况*/


class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n, n);
    }
    vector<string> find(int m, int n) {
        if (m == 0) return {""};
        if (m == 1) return {"0", "1", "8"};
        vector<string> t = find(m - 2, n);
        vector<string> res;
        for (string s : t) {
            if (m != n) res.push_back("0" + s + "0");
            res.push_back("1" + s + "1");
            res.push_back("6" + s + "9");
            res.push_back("8" + s + "8");
            res.push_back("9" + s + "6");
        }
        return res;
    }
};


/* 这道题迭代的解法，需要从奇偶来考虑，奇数赋为0,1,8，偶数赋为空，如果是奇数，就从i=3开始搭建，因为计算i=3需要i=1，
而我们已经初始化了i=1的情况，如果是偶数，我们从i=2开始搭建，我们也已经初始化了i=0的情况，所以我们可以用for循环来搭建
到i=n的情况，思路和递归一样 */

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> one{"0", "1", "8"};
        vector<string> two{""};
        vector<string> res = two;
        if (n % 2 == 1) res = one;
        for (int i = (n % 2) + 2; i <= n; i += 2) {
            vector<string> t;
            for (auto a : res) {
                if (i != n) t.push_back("0" + a + "0");
                t.push_back("1" + a + "1");
                t.push_back("6" + a + "9");
                t.push_back("8" + a + "8");
                t.push_back("9" + a + "6");
            }
            res = t;
        }
        return res;
    }
};







