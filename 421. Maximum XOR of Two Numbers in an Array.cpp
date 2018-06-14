/*421. Maximum XOR of Two Numbers in an Array

Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
Could you do this in O(n) runtime?

Example:
Input: [3, 10, 5, 25, 2, 8]
Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.

我们来分析一下这道题的核心。我们希望用二进制来拼出结果的数，最终结果28的二进制数为11100，里面有三个‘1’，
我们来找一下都是谁贡献了这三个‘1’？在 i=4 时，数字25贡献了最高位的‘1’，在 i=3 时，数字25贡献了次高位的‘1’，
在 i=2 时，数字5贡献了第三位的‘1’。而一旦某个数贡献了‘1’，那么之后在需要贡献‘1’的时候，此数就可以再继续贡献‘1’。
而一旦有两个数贡献了‘1’后，那么之后的‘1’就基本上只跟这两个数有关了，其他数字有‘1’也贡献不出来。验证方法里使用了
前面提到的性质，a ^ b = t，如果t是所求结果话，我们可以先假定一个t，然后验证，如果a ^ t = b成立，说明该t可以通过
a和b‘异或’得到。参见代码如下：*/
 
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int t = res | (1 << i);
            for (int prefix : s) {
                if (s.count(t ^ prefix)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};















