/* 204. Count Primes

Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/


class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        isPrime[0] = false, isPrime[1] = false;
        for (int i = 0; i < sqrt(n); i++) {
            if (isPrime[i]) {
                for (int j = i*i; j < n; j += i) {
                    isPrime[j] = false;
                }    
            }    
        }
        return count(isPrime.begin(), isPrime.end(), true);
    }
};






