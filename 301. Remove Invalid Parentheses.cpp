/*301. Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. 
Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:
Input: "()())()"
Output: ["()()()", "(())()"]

Example 2:
Input: "(a)())()"
Output: ["(a)()()", "(a())()"]

Example 3:
Input: ")("
Output: [""]

*/

/*这道题让我们移除最少的括号使得给定字符串为一个合法的含有括号的字符串，字符串中的左右括号数应该相同，而且每个右括号左边
一定有其对应的左括号，而且题目中给的例子也说明了去除方法不唯一，我们需要找出所有合法的取法。这道题首先可以用BFS来解，我们
先把给定字符串排入队中，然后取出检测其是否合法，若合法直接返回，不合法的话，我们对其进行遍历，对于遇到的左右括号的字符，
去掉括号字符生成一个新的字符串，如果这个字符串之前没有遇到过，将其排入队中，我们用哈希集合记录一个字符串是否出现过。
我们对队列中的每个元素都进行相同的操作，直到队列为空还没找到合法的字符串的话，那就返回空集 */

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited{{s}};
        queue<string> q{{s}};
        bool found = false;
        while (!q.empty()) {
            string t = q.front(); 
            q.pop();
            if (isValid(t)) {
                res.push_back(t);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < t.size(); ++i) {
                if (t[i] != '(' && t[i] != ')') continue;
                string str = t.substr(0, i) + t.substr(i + 1);
                if (!visited.count(str)) {
                    q.push(str);
                    visited.insert(str);
                }
            }
        }
        return res;
    }

    bool isValid(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') count++;
            else if (s[i] == ')') count--;
            if (count<0) return false;
        }
        return count == 0;
    }
};

/*还有一种递归解法，这种解法首先统计了多余的半括号的数量，用cnt1表示多余的左括号，cnt2表示多余的右括号，因为给定字符串左右
括号要么一样多，要么左括号多，要么右括号多，也可能左右括号都多，比如")("。所以cnt1和cnt2要么都为0，要么都大于0，要么一个为0，
另一个大于0。好，下面进入我们的递归函数，首先判断，如果当cnt1和cnt2都为0时，说明此时左右括号个数相等了，我们调用isValid子函数
来判断是否正确，正确的话加入结果res中并返回即可。否则从start开始遍历，这里的变量start表示当前递归开始的位置，我们不需要每次都
从头开始，会有大量重复计算。而且对于多个相同的半括号在一起，我们只删除第一个，比如"())"，这里有两个右括号，我们不管删第一个还是
删第二个右括号都会得到"()"，没有区别，所以只用算一次就行了，我们通过和上一个字符比较，如果不相同，说明是第一个右括号，如果相同
则直接跳过。此时来看如果cnt1大于0，说明此时左括号多，而如果当前字符正好是左括号的时候，我们可以删掉当前左括号，继续调用递归，
此时cnt1的值就应该减1，因为已经删掉了一个左括号。同理，如果cnt2大于0，说明此时右括号多，而如果当前字符正好是右括号的时候，
我们可以删掉当前右括号，继续调用递归，此时cnt2的值就应该减1，因为已经删掉了一个右括号*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int count1 = 0, count2 = 0;
        for (char c : s) {
            if (c == '(') {
                count1++;
            }else if (c == ')') {
                if(count1 == 0) count2++;
                else count1--;
            }
        }
        dfs(s, 0, count1, count2, res);
        return res;
    }
    
    void dfs(string s, int start, int count1, int count2, vector<string>& res) {
        if (count1 == 0 && count2 == 0 && isValid(s)) {
            res.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (i > start && s[i] == s[i-1]) 
                continue;
            if (count1 > 0 && s[i] == '(') {
                dfs(s.substr(0,i) + s.substr(i+1), i, count1-1, count2, res);
            }
            if (count2 > 0 && s[i] == ')') {
                dfs(s.substr(0,i) + s.substr(i+1), i, count1, count2-1, res);
            }
        }
    }
    
    bool isValid(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') count++;
            else if (s[i] == ')') count--;
            if (count<0) return false;
        }
        return count == 0;
    }
};