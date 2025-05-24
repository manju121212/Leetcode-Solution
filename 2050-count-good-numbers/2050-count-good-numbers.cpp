class Solution {
public:

const long long MOD = 1e9 + 7;

// Function to compute (base^exp) % mod using binary exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; // Even indices
    long long oddCount = n / 2;        // Odd indices

    long long evenWays = modPow(5, evenCount, MOD); // 5 choices for even indices
    long long oddWays = modPow(4, oddCount, MOD);   // 4 choices for odd indices

    return (evenWays * oddWays) % MOD; 


    }
};