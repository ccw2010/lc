/*243. Shortest Word Distance

Given a list of words and two words word1 and word2, return the shortest distance between 
these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.*/

/*我们遍历一次数组就可以了，用两个变量p1,p2初始化为-1，然后我们遍历数组，遇到单词1，就将其位置存在p1里，
若遇到单词2，就将其位置存在p2里，如果此时p1, p2都不为-1了，那么我们更新结果。此题不能用hash table， 原因
是可能遇到 words = ["a","a","b","b"], word1 = "a", word2 = "b" 的情况 */


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1;
        int res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) p1 = i;
            else if (words[i] == word2) p2 = i;
            if (p1 != -1 && p2 != -1) res = min(res, abs(p1 - p2));
        }
        return res;
    }
};




