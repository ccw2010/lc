/*241. Different Ways to Add Parentheses

Given a string of numbers and operators, return all possible results from computing all the different 
possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:
Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2

Example 2:
Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

/*这道题让给我们一个可能含有加减乘的表达式，让我们在任意位置添加括号，求出所有可能表达式的不同值。这道题跟之前的那道
Unique Binary Search Trees II 独一无二的二叉搜索树之二用的方法一样，用递归来解，划分左右子树，递归构造。*/

class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(s.substr(0, i));
                vector<int> right = diffWaysToCompute(s.substr(i+1));
                for (int x : left) {
                    for (int y : right) {
                        if (c == '+') res.push_back(x + y);
                        else if (c == '-') res.push_back(x - y);
                        else res.push_back(x * y);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(atoi(s.c_str()));
        return res;
    }
};










