/*
Longest Common Prefix 最长共同前缀
 
Write a function to find the longest common prefix string amongst an array of strings.

定义两个变量i和j，其中i是遍历搜索字符串中的字符，j是遍历字符串集中的每个字符串。这里将单词上下排好，则相当于一个
各行长度有可能不相等的二维数组，我们遍历顺序和一般的横向逐行遍历不同，而是采用纵向逐列遍历，在遍历的过程中，如果
某一行没有了，说明其为最短的单词，因为共同前缀的长度不能长于最短单词，所以此时返回已经找出的共同前缀。我们每次取
出第一个字符串的某一个位置的单词，然后遍历其他所有字符串的对应位置看是否相等，如果有不满足的直接返回res，如果都
相同，则将当前字符存入结果，继续检查下一个位置的字符
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res;
        int n_strs = strs.size();
        int len0 = strs[0].size();
        for (int j=0; j< len0; j++){
            char c = strs[0][j];
            for (int i=0; i< n_strs; i++){
                if (strs[i][j] != c || strs[i].size() < j){
                    return res;
                }
            }
            res += c;
        }
        return res;
    }
};




