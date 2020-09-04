class Solution {
  public:
    int countPrimes(int n) {
        // edge
        if (n <= 1)
            return 0;
        // sieve of eratosthenes
        vector<bool> isPrime(n, true);
        isPrime[0] = false, isPrime[1] = false;
        for (int i = 2; i * i < n; i++)
            if (isPrime[i])
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;
        // sum up and return
        int ans = 0;
        for (bool b : isPrime)
            if (b)
                ans++;
        return ans;
    }
};