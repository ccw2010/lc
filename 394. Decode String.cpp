/*394. Decode String

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated 
exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those 
repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

/*这道题让我们把一个按一定规则编码后的字符串解码成其原来的模样，编码的方法很简单，就是把重复的字符串放在一个中括号里，
把重复的次数放在中括号的前面，注意中括号里面有可能会嵌套中括号，这题可以用递归和迭代两种方法来解，我们首先来看递归的解法，
我们把一个中括号中的所有内容看做一个整体，一次递归函数返回一对中括号中解码后的字符串。给定的编码字符串实际上只有四种字符，
数字，字母，左中括号，和右中括号。那么我们开始用一个变量i从0开始遍历到字符串的末尾，由于左中括号都是跟在数字后面，所以我们
首先遇到的字符只能是数字或者字母，如果是字母，我们直接存入结果中，如果是数字，我们循环读入所有的数字，并正确转换，那么下一位
非数字的字符一定是左中括号，我们指针右移跳过左中括号，对之后的内容调用递归函数求解，注意我们循环的停止条件是遍历到末尾和遇到
右中括号，由于递归调用的函数返回了子中括号里解码后的字符串，而我们之前把次数也已经求出来了，那么循环添加到结果中即可*/


class Solution {
public:
   string decode(const string& s, int& i) {
        string res;
        int len = s.size();
        while (i < len && s[i] != ']') {
            if (islower(s[i]) || isupper(s[i])){
                res += s[i++];
            }else {
                int num = 0;
                while (i < len && isdigit(s[i])){
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                    
                i++; // '['
                string t = decode(s, i);
                i++; // ']'
                
                while (num-- > 0){
                    res += t;
                }
            }
        }
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};







