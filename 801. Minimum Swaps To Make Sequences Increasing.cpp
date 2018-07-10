/*801. Minimum Swaps To Make Sequences Increasing

We have two integer sequences A and B of the same non-zero length.
We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position 
in their respective sequences.

At the end of some number of swaps, A and B are both strictly increasing.  (A sequence is strictly 
increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)

Given A and B, return the minimum number of swaps to make both sequences strictly increasing.  It is
guaranteed that the given input always makes it possible.

Example:
Input: A = [1,3,5,4], B = [1,2,3,7]
Output: 1
Explanation: 
Swap A[3] and B[3].  Then the sequences are:
A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
which are both strictly increasing.

Note:
- A, B are arrays with the same length, and that length will be in the range [1, 1000].
- A[i], B[i] are integer values in the range [0, 2000].
*/

/* swap[n] means the minimum swaps to make the A[i] and B[i] sequences increasing for 0 <= i <= n in
condition that we swap A[n] and B[n], notSwap[n] is the same with A[n] and B[n] not swapped. */


class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int notSwap[n] = {0};
        int swap[n] = {1};
        for (int i = 1; i < n; i++) {
            notSwap[i] = swap[i] = n;
            if (A[i-1] < A[i] && B[i-1] < B[i]) {
                notSwap[i] = notSwap[i-1];
                swap[i] = swap[i-1] + 1;
            }
            if (A[i-1] < B[i] && B[i-1] < A[i]) {
                notSwap[i] = min(notSwap[i], swap[i-1]);
                swap[i] = min(swap[i], notSwap[i-1] + 1);
            }
        }
        return min(swap[n-1], notSwap[n-1]);
    }
};








