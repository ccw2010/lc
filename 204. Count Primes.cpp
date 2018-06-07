/*204. Count Primes

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n - 1, true);
        prime[0] = false;
        int res = 0;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (prime[i - 1]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j - 1] = false;
                }
            }
        }
        for (int j = 0; j < n - 1; ++j) {
            if (prime[j]) res++;
        }
        return res;
        
    }
};

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 0; i < sqrt(n); i++) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }    
            }    
        }
        return count(prime.begin(), prime.end(), true);
    }
};


















