/*165. Compare Version Numbers

Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth 
second-level revision of the second first-level revision.

Example 1:
Input: version1 = "0.1", version2 = "1.1"
Output: -1

Example 2:
Input: version1 = "1.0.1", version2 = "1"
Output: 1

Example 3:
Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
*/

/*由于两个版本号所含的小数点个数不同，有可能是1和1.1.1比较，还有可能开头有无效0，比如01和1就是相同版本，
还有可能末尾无效0，比如1.0和1也是同一版本。对于没有小数点的数字，可以默认为最后一位是小数点，而版本号比较
的核心思想是相同位置的数字比较，比如题目给的例子，1.2和13.37比较，我们都知道应该显示1和13比较，13比1大，
所以后面的不用再比了，再比如1.1和1.2比较，前面都是1，则比较小数点后面的数字。那么算法就是每次对应取出相同
位置的小数点之前所有的字符，把他们转为数字比较，若不同则可直接得到答案，若相同，再对应往下取。如果一个数字
已经没有小数点了，则默认取出为0，和另一个比较，这样也解决了末尾无效0的情况*/


class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0, d1 = 0, d2 = 0;
        string v1, v2;
        while (i < n1 || j < n2) {
            while (i < n1 && version1[i] != '.') {
                v1.push_back(version1[i++]);
            }
            d1 = atoi(v1.c_str());
            while (j < n2 && version2[j] != '.') {
                v2.push_back(version2[j++]);
            }
            d2 = atoi(v2.c_str());
            if (d1 > d2) return 1;
            else if (d1 < d2) return -1;
            v1.clear(); 
            v2.clear();
            i++; 
            j++;
        }
        return 0;
        
    }
};












