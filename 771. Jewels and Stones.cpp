/* 771. Jewels and Stones

You're given strings jewels representing the types of stones that are jewels, and stones representing 
the stones you have.  Each character in stones is a type of stone you have.  You want to know how many 
of the stones you have are also jewels.

The letters in jewels are guaranteed distinct, and all characters in jewels and S are letters. Letters 
are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

Example 2:
Input: jewels = "z", stones = "ZZ"
Output: 0
*/


/*这道题给了我们两个字符串，jewels和stones，其中jewels中的每个字符都是珠宝，stones中的每个字符都是石头，问我们
stones中有多少个珠宝。我们用set来优化时间复杂度，将珠宝字符串jewels中的所有字符都放入set中，然后遍历石头字符串中
的每个字符，到set中查找是否存在，存在的话计数器自增1即可*/

class Solution {
public:
    int numJewelsInStones(string c, string stones) {
        int res = 0;
        unordered_set<char> s(jewels.begin(), jewels.end());
        for (char c : stones) {
        	if (s.count(c)) res++;
        }
        return res;
    }
};







