/* 500. Keyboard Row
Given a List of words, return the words that can be typed using letters of alphabet on only one 
row's of American keyboard like the image below.

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.

这道题给了我们一些单词，问哪些单词可以由键盘上的一行中的键符打出来。
首先我们把键盘的三行字符分别保存到三个set中，然后遍历每个单词中的每个字符，分别看当前字符是否在三个集合中，
如果在，对应的标识变量变为1，我们统计三个标识变量之和就知道有几个集合参与其中了*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> ans;
        unordered_set<char> row1 = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2 = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3 = {'z','x','c','v','b','n','m'};
        for (string word : words){
            int count1 = 0, count2 = 0, count3 = 0;
            for (char c : word){
                if (c < 'a') c += 32;
                if (row1.count(c)) count1 = 1;
                if (row2.count(c)) count2 = 1;
                if (row3.count(c)) count3 = 1;
                if (count1 + count2 + count3 > 1) break;
            }
            if (count1 + count2 + count3 == 1) ans.push_back(word);
        }
        return ans;
    }
};


