/*696. Count Binary Substrings
Give a string s, count the number of non-empty (contiguous) substrings that have the same number 
of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", 
"1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's 
and 0'*/


/*First, I count the number of 1 or 0 grouped consecutively.
For example "0110001111" will be [1, 2, 3, 4].

Second, for any possible substrings with 1 and 0 grouped consecutively, the number of valid substring 
will be the minimum number of 0 and 1.
For example "0001111", will be min(3, 4) = 3, ("01", "0011", "000111") */

/*这道题给了我们一个二进制字符串，然后我们统计具有相同0和1的个数，且0和1各自都群组在一起(即0和1不能交替出现)的子字
符串的个数。下面这种方法直接用了pre和cur两个变量，其中pre初始化为0，cur初始化为1，然后从第二个数字开始遍历，如果当
前数字和前面的数字相同，则cur自增1，否则pre赋值为cur，cur重置1。然后判断如果pre大于等于cur，res自增1。其实核心思
想跟上面的方法一样，只不过pre和cur可以在0和1之间切换*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int pre = 0, cur = 1;
        int res = 0;        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) cur++;
            else {
                res += min(pre, cur);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(pre, cur);       
    }
};












