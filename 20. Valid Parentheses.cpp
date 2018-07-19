/*20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for (char c : s) {
            if (c == '(') t.push(')');
            else if (c == '[') t.push(']');
            else if (c == '{') t.push('}');
            else {
                if (t.empty() || t.top() != c) return false;
                else t.pop();
            }
        }
        return t.empty();
    }
};


class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        int n = s.size();
        if (n%2) return false;
        stack<char> t;
        set<char> opening = {'(', '[', '{'};
        set<char> closing = {')', ']', '}'};
        for (auto c : s){
            if (opening.count(c)){
                t.push(c);
            }else if(closing.count(c)){
                if(t.empty()) return false;
                auto p = t.top(); t.pop();
                if(c==')' && p!='(') return false;
                else if(c==']' && p!='[') return false;
                else if(c=='}' && p!='{') return false;
            }
        }
        return t.empty();
    }
};








