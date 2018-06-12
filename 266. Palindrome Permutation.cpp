/*266. Palindrome Permutation
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:
Input: "code"
Output: false

Example 2:
Input: "aab"
Output: true

Example 3:
Input: "carerac"
Output: true */

/*这道题让我们判断一个字符串的全排列有没有是回文字符串的，那么根据题目中的提示，我们分字符串的个数是奇偶的情况来讨论，
如果是偶数的话，由于回文字符串的特性，每个字母出现的次数一定是偶数次，当字符串是奇数长度时，只有一个字母出现的次数是奇数，
其余均为偶数，那么利用这个特性我们就可以解题，我们建立每个字母和其出现次数的映射，然后我们遍历哈希表，统计出现次数为奇数
的字母的个数，那么只有两种情况是回文数，第一种是没有出现次数为奇数的字母，再一个就是字符串长度为奇数，且只有一个出现次数
为奇数的字母*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int count = 0;
        for (char c: s) m[c]++;
        for (auto &x : m){
            if(x.second %2) count++;
        }
        return count==0 || (s.size()%2==1 && count==1);
    }
};








