/*245. Shortest Word Distance III

Given a list of words and two words word1 and word2, return the shortest distance between 
these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1

Input: word1 = "makes", word2 = "makes"
Output: 3
*/

/*这道题还是让我们求最短单词距离，有了之前243.Shortest Word Distance和244.Shortest Word Distance II的基础，就
大大降低了题目本身的难度。这道题增加了一个条件，就是说两个单词可能会相同，所以在第一题中的解法的基础上做一些修改，我最
先想的解法是基于第一题中的解法二，由于会有相同的单词的情况，那么p1和p2就会相同，这样结果就会变成0，显然不对，所以我们
要对word1和word2是否的相等的情况分开处理，如果相等了，由于p1和p2会相同，所以我们需要一个变量t来记录上一个位置，这样
如果t不为-1，且和当前的p1不同，我们可以更新结果，如果word1和word2不等，那么还是按原来的方法做*/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            int t = p1;
            if (words[i] == word1) p1 = i;
            if (words[i] == word2) p2 = i;
            if (p1 != -1 && p2 != -1) {
                if (word1 == word2 && t != -1 && t != p1) {
                    res = min(res, abs(t - p1));
                } else if (p1 != p2) {
                    res = min(res, abs(p1 - p2));
                }
            }
        }
        return res;
    }
};








