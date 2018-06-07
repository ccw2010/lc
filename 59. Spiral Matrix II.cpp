/*59. Spiral Matrix II
DescriptionHintsSubmissionsDiscussSolution

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n<=0) return {};
        vector<vector<int> > res(n, vector<int>(n, 1));

        // Normal Case
        int top = 0, right = n-1;
        int left = 0, bottom = n-1;
      
        int val = 1; //change    
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                res[top][i] = val++; //change
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                res[i][right] = val++; //change
            }
            right--;
            
            for (int i = right; i >= left; i--) {
                if (top <= bottom)
                    res[bottom][i] = val++; //change
            }
            bottom--;
            
            for (int i = bottom; i >= top; i--) {
                if (left <= right)
                    res[i][left] = val++; //change
            }
            left++;
        }
        return res;
    }
};