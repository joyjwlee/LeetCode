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

    int countPrimeSetBits(int L, int R) {
        // init
        int ans = 0;
        int num, n;

        // loop through all
        for (int i = L; i <= R; i++) {
            // count number of odd bits
            num = 0, n = i;
            while (n) {
                if (n % 2 == 1)
                    num++;
                n >>= 1;
            }
            // increment if prime
            if (isPrime(num))
                ans++;
        }
        return ans;
    }
};