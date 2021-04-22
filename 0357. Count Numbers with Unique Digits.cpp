class Solution {
  public:
    int countNumbersWithUniqueDigits(int n) {
        // for each additional digit see how many other choices you have
        int ans = 1, prod = 1;
        for (int i = 1; i <= n; i++) {
            prod = 9;
            for (int j = 0; j < i - 1; j++)
                prod *= (9 - j);
            ans += prod;
        }
        return ans;
    }
};