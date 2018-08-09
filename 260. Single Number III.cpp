/* 260. Single Number III 

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements 
appear exactly twice. Find the two elements that appear only once.

For example: Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note: The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space 
complexity?
*/


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> m;
        for (auto n : nums) m[n]++;
        for (auto c : m){
            if(c.second == 1) res.push_back(c.first);
        }
        return res;
    }
};


/* 这道题是之前136.Single Number 和 137.Single Number II的再次延伸，这类位操作Bit Manipulation的题，
如果之前没有遇到过类似的题目，是很难想出来的。这道题其实是很巧妙的利用了136.Single Number 单独的数字的解法，
因为那道解法是可以准确的找出只出现了一次的数字，但前提是其他数字必须出现两次才行。而这题有两个数字都只出现了
一次，那么我们如果能想办法把原数组分为两个小数组，不相同的两个数字分别在两个小数组中，这样分别调用136的解法
就可以得到答案。那么如何实现呢，首先我们先把原数组全部异或起来，那么我们会得到一个数字，这个数字是两个不相同
的数字异或的结果，我们取出其中任意一位为‘1’的位，为了方便起见，我们用 a &= -a 来取出最右端为‘1’的位，然后
和原数组中的数字挨个相与，那么我们要求的两个不同的数字就被分到了两个小组中，分别将两个小组中的数字都异或起来，
就可以得到最终结果了 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> res(2, 0);
        for (auto &n : nums) {
            if (n & diff) res[0] ^= n;
            else res[1] ^= n;
        }
        return res;
    }
};





