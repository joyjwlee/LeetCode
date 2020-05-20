class Solution {
  public:
    int reverse(int x) {
        int digit, ans = 0;
        while (x) {
            if (ans > 0 && ans > INT_MAX / 10)
                return 0;
            if (ans < 0 && ans < INT_MIN / 10)
                return 0;
            ans *= 10;
            int digit = x % 10;
            if (ans > 0 && ans > INT_MAX - digit)
                return 0;
            if (ans < 0 && ans < INT_MIN - digit)
                return 0;
            ans += digit;
            x /= 10;
        }
        return ans;
    }
};