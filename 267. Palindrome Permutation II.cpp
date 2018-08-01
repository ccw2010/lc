/* 267. Palindrome Permutation II 

Given a string s, return all the palindromic permutations (without duplicates) of it. 
Return an empty list if no palindromic permutation could be form.

For example:
Given s = "aabb", return ["abba", "baab"].
Given s = "abc", return [].

Hint:
If a palindromic permutation exists, we just need to generate the first half of the string.
To generate all distinct permutations of a (half of) string, use a similar approach from: 
Permutations II or Next Permutation.
*/

/* 这道题让我们返回所有的回文全排列，此题给了我们充分的提示：如果回文全排列存在，我们只需要生成前半段字符串即可，
后面的直接根据前半段得到。那么我们再进一步思考，由于回文字符串有奇偶两种情况，偶数回文串例如abba，可以平均分成
前后半段，而奇数回文串例如abcba，需要分成前中后三段，需要注意的是中间部分只能是一个字符，那么我们可以分析得出，
如果一个字符串的回文字符串要存在，那么奇数个的字符只能有0个或1个，其余的必须是偶数个，所以我们可以用哈希表来记录
所有字符的出现个数，然后我们找出出现奇数次数的字符加入mid中，如果有两个或两个以上的奇数个数的字符，那么返回空集，
我们对于每个字符，不管其奇偶，都将其个数除以2的个数的字符加入t中，这样做的原因是如果是偶数个，那么将其一般加入t中，
如果是奇数，如果有1个，那么除以2是0，不会有字符加入t，如果是3个，那么除以2是1，取一个加入t。等我们获得了t之后，
t是就是前半段字符，我们对其做全排列，每得到一个全排列，我们加上mid和该全排列的逆序列就是一种所求的回文字符串，
这样我们就可以得到所有的回文全排列了 */
 

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        string t = "", mid = "";
        for (auto a : s) ++m[a];
        for (auto it : m) {
            if (it.second % 2 == 1) mid += it.first;
            t += string(it.second / 2, it.first);
            if (mid.size() > 1) return {};
        }
        permute(t, 0, mid, res);
        return res;
    }
    void permute(string &t, int start, string mid, vector<string> &res) {
        if (start >= t.size()) {
            res.push_back(t + mid + string(t.rbegin(), t.rend()));
        } 
        for (int i = start; i < t.size(); ++i) {
            if (i != start && t[i] == t[start]) continue;
            swap(t[i], t[start]);
            permute(t, start + 1, mid, res);
            swap(t[i], t[start]);
        }
    }
};






