/* 249. Group Shifted Strings

Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". 
We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same 
shifting sequence.

Example:
Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
] */


/*这道题让我们重组偏移字符串，所谓偏移字符串，就是一个字符串的每个字符按照字母顺序表偏移相同量得到的另一个字符串，
两者互为偏移字符串，注意相同字符串是偏移字符串的一种特殊情况，因为偏移量为0。现在给了我们一堆长度不同的字符串，让
我们把互为偏移字符串的归并到一起，我们可以更加巧妙的利用偏移字符串的特点，那就是字符串的每个字母和首字符的相对距离
都是相等的，比如abc和efg互为偏移，对于abc来说，b和a的距离是1，c和a的距离是2，对于efg来说，f和e的距离是1，g和e的
距离是2。再来看一个例子，az和yx，z和a的距离是25，x和y的距离也是25(直接相减是-1，这就是要加26然后取余的原因)，那么
这样的话，所有互为偏移的字符串都有个unique的距离差，我们根据这个来建立映射就可以很好的进行单词分组了*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, multiset<string>> m;
        for (auto str : strings) {
            string t = "";
            for (char c : str) {
                t += to_string((c + 26 - str[0]) % 26) + ",";
            }
            m[t].insert(str);
        }
        for (auto &x : m) {
            vector<string> shift(x.second.begin(), x.second.end());
            res.push_back(shift);
        }
        return res;
    }
};








