/*227. Basic Calculator II

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces. 
The integer division should truncate toward zero.

Example 1:
Input: "3+2*2"
Output: 7

Example 2:
Input: " 3/2 "
Output: 1

Example 3:
Input: " 3+5 / 2 "
Output: 5 */

/*这道题是 Basic Calculator 的拓展，不同之处在于那道题的计算符号只有加和减，而这题加上了乘除，那么就牵扯到了运算优先级的问题，
好在这道题去掉了括号，适当的降低了难度。这道题先按没有括号来处理，由于存在运算优先级，我们采取的措施是使用一个栈保存数字，如果该
数字之前的符号是加或减，那么把当前数字压入栈中，注意如果是减号，则加入当前数字的相反数，因为减法相当于加上一个相反数。如果之前的
符号是乘或除，那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中，那么完成一遍遍历后，所有的乘或除都运算完了，再
把栈中所有的数字都加起来就是最终结果了。*/

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        unordered_set<char> ops{'+', '-', '*', '/'};
        char op = '+';
        stack<int> t;
        int num = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            if (ops.count(c) || i == n-1) {
                if (op == '+') t.push(num);
                if (op == '-') t.push(-num);
                if (op == '*' || op == '/') {
                    int tmp;
                    if (op == '*') tmp = t.top() * num;
                    if (op == '/') tmp = t.top() / num;
                    t.pop();
                    t.push(tmp);
                }
                op = c;
                num = 0;
            } 
        }
        int res = 0;
        while (!t.empty()) {
            res += t.top();
            t.pop();
        }
        return res;    
    }
};
 

/*在做了Basic Calculator III之后，再反过头来看这道题，发现只要将处理括号的部分去掉直接就可以在这道题上使用*/

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int curRes = 0;
        int num = 0;
        int n = s.size();
        char op = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
                switch (op) {
                    case '+': curRes += num; break;
                    case '-': curRes -= num; break;
                    case '*': curRes *= num; break;
                    case '/': curRes /= num; break;
                }
                if (c == '+' || c == '-' || i == n-1) {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            } 
        }
        return res;
    }
};







