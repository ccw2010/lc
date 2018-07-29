/*89. Gray Code

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence 
of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.*/


class Solution {
public:
    void dfs(bitset<32>& bits, vector<int>& result, int k){
        if (k==0) {
            result.push_back(bits.to_ulong());
        } else {
            dfs(bits, result, k-1);
            bits.flip(k-1);
            dfs(bits, result, k-1);
        }
    }

    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        dfs(bits, result, n);
        return result;
    }
};



class Solution {
public:
    vector<int> grayCode(int n) {         
        vector<int> result(1, 0);      
        int   
        for (int i = 0; i < n; i++) {
            int count = result.size();
            // push back all element in result in reverse order
            while (count) {
                count--;
                int num = result[count];
                num += (1<<i);
                result.push_back(num);
            } 
        }
        return result;
    }
};










