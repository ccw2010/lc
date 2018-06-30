/*531. Lonely Pixel I

Given a picture consisting of black and white pixels, find the number of black lonely pixels.

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white 
pixels respectively.

A black lonely pixel is character 'B' that located at a specific position where the same row and same 
column don't have any other black pixels.

Example:
Input: 
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]

Output: 3
Explanation: All the three 'B's are black lonely pixels.

Note: The range of width and height of the input 2D array is [1,500]. */

/*这道题定义了一种孤独的黑像素，就是该黑像素所在的行和列中没有其他的黑像素，让我们找出所有的这样的像素。
那么既然对于每个黑像素都需要查找其所在的行和列，为了避免重复查找，我们可以统一的扫描一次，将各行各列的黑像素
的个数都统计出来，然后再扫描所有的黑像素一次，看其是否是该行该列唯一的存在，是的话就累加计数器即可*/

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if (picture.empty() || picture[0].empty()) return 0;
        int nrows = picture.size(), ncols = picture[0].size();
        vector<int> rowCnt(nrows, 0), colCnt(ncols, 0);
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                if (picture[i][j] == 'B') {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                if (picture[i][j] == 'B' && rowCnt[i] == 1 && colCnt[j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};








