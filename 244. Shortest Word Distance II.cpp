/* 244. Shortest Word Distance II

Design a class which receives a list of words in the constructor, and implements a method that takes 
two words word1 and word2 and return the shortest distance between these two words in the list. Your 
method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3

Input: word1 = "makes", word2 = "coding"
Output: 1 */


/*这道题是243.Shortest Word Distance的拓展，不同的是这次我们需要多次调用求最短单词距离的函数，那么用之前那道题的
解法二和三就非常不高效，而当时我们摒弃的解法一的思路却可以用到这里，我们用哈希表来建立每个单词和其所有出现的位置的映射，
然后在找最短单词距离时，我们只需要取出该单词在哈希表中映射的位置数组进行两两比较即可*/

class WordDistance {
private:
    unordered_map<string, vector<int>> m;
    
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int res = INT_MAX;
        int len1 = m[word1].size();
        int len2 = m[word2].size();
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                res = min(res, abs(m[word1][i] - m[word2][j]));
            }
        }
        return res;
    }
};
/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */


/*我们可以优化上述的代码，使查询的复杂度由上面的O(MN)变为O(M+N)，其中M和N为两个单词的长度，我们需要两个指针i和j来
指向位置数组中的某个位置，开始初始化都为0，然后比较位置数组中的数字，将较小的一个的指针向后移动一位，直至其中一个数
组遍历完成即可*/

class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0;
        int res = INT_MAX;
        int len1 = m[word1].size();
        int len2 = m[word2].size();
        while (i < len1 && j < len2) {
            res = min(res, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? i++ : j++;
        }
        return res;
    }
    
private:
    unordered_map<string, vector<int>> m;
};





