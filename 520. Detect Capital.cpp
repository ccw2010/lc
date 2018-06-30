/*Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

1.All letters in this word are capitals, like "USA".
2.All letters in this word are not capitals, like "leetcode".
3.Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:
Input: "USA"
Output: True

Example 2:
Input: "FlaG"
Output: False

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.*/

/* 这道题给了我们一个单词，让我们检测大写格式是否正确，规定了三种正确方式，要么都是大写或小写，要么首字母大写，
其他情况都不正确。那么我们要做的就是统计出单词中所有大写字母的个数count，再来判断是否属于这三种情况，如果count为0，
说明都是小写，正确；如果count和单词长度相等，说明都是大写，正确；如果count为1，且首字母为大写，正确，其他情况均false */

#include <ctype.h>

class Solution {
public:
    bool detectCapitalUse(const string &word) {
        int count = 0;
        for (char &c : word){
            if (isupper(c)) count++;
        }
        return count==0 || count==word.size() || (count==1 && isupper(word[0]));        
    }
};





