/*119. Pascal's Triangle II 
 
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note: Could you optimize your algorithm to use only O(k) extra space?


杨辉三角:
　　　　　　　　１
　　　　　　　１　１
　　　　　　１　２　１
　　　　　１　３　３　１
　　　　１　４　６　４　１
　　　１　５　10　10　５　１
　　１　６　15　20　15　６　１
　１　７　21　35　35　21　７　１
１　８　28　56　70　56　28　８　１*/

/*除了第一个和最后一个数字之外，其他的数字都是上一行左右两个值之和。那么我们只需要两个for循环，除了第一个数为1之外，
后面的数都是上一次循环的数值加上它前面位置的数值之和，不停地更新每一个位置的值，便可以得到第n行的数字*/

class Solution {
public:
    vector<int> getRow(int n) {
        if (n < 0) return {};
        vector<int> res;
        res.assign(n+1, 0);
        res[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= 1; j--) {
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }
};








