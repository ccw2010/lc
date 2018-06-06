/*150. Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:
Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result 
and there won't be any divide by zero operation.

Example 1:
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

/*我们可以用递归来做，由于一个有效的逆波兰表达式的末尾必定是操作符，所以我们可以从末尾开始处理，如果遇到操作符，
向前两个位置调用递归函数，找出前面两个数字，然后进行操作将结果返回，如果遇到的是数字直接返回即可*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i = tokens.size() - 1;
        return dfs(tokens, i);
    }
    int dfs(vector<string> & tokens, int &i){
        string s = tokens[i];
        unordered_set<string> ops{"+", "-", "*", "/"};
        if (ops.count(s)){
            i--;
            int n2 = dfs(tokens, i);
            i--;
            int n1 = dfs(tokens, i);
            if (s == "+") return n1 + n2;
            else if (s == "-") return n1 - n2;
            else if (s == "*") return n1 * n2;
            else if (s == "/") return n1 / n2;
        }else{
            return stoi(s);
        }
    }
};







