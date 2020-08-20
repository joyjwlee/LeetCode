class Solution {
  public:
    int trailingZeroes(int n) {
        // basically count number of 5s
        int ans = 0;
        for (long int i = 5; n / i >= 1; i *= 5)
            ans += n / i;
        return ans;
    }
};