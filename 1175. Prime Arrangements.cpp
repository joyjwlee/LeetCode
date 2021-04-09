class Solution {
  public:
    bool isPrime(int n) {
        // edge
        if (n == 0 || n == 1)
            return false;

        // loop until sqrt
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;

        // otherwise return true
        return true;
    }

    int numPrimeArrangements(int n) {
        // init
        long int ans = 1, mod = 1e9 + 7;
        int primes = 0, composites = 0;

        // find number of primes and composites
        for (int i = 1; i <= n; i++) {
            if (isPrime(i))
                primes++;
            else
                composites++;
        }

        // loop through both
        while (primes) {
            ans *= primes;
            ans %= mod;
            primes--;
        }
        while (composites) {
            ans *= composites;
            ans %= mod;
            composites--;
        }
        return ans;
    }
};