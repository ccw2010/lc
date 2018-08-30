/*32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid 
(well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"*/


/*这道求最长有效括号比20.Valid Parentheses 验证括号难度要大一些，这里我们还是借助栈来求解，需要定义个start变量
来记录合法括号串的起始位置，我们遍历字符串，如果遇到左括号，则将当前下标压入栈，如果遇到右括号，如果当前栈为空，则
将下一个坐标位置记录到start，如果栈不为空，则将栈顶元素取出，此时若栈为空，则更新结果和i - start + 1中的较大值，
否则更新结果和i - 栈顶元素中的较大值*/

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.emtpy()) return 0;
        int res = 0, start = 0;
        int n = s.size();
        stack<int> t;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                t.push(i);
            } else if (s[i] == ')') {
                if (t.empty()) {
                    start = i + 1;
                } else {
                    t.pop();
                    if (t.empty()) res = max(res, i-start+1) ;
                    else res = max(res, i-t.top());
                }
            }
        }
        return res;
    }
};






