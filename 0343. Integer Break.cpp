class Solution {
  public:
    int integerBreak(int n) {
        // edge
        if (n == 2 || n == 3)
            return n - 1;

        // loop through
        int prod = 1;
        while (n > 4) {
            n -= 3;
            prod *= 3;
        }
        return n * prod;
    }
};