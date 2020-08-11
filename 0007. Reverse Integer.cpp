class Solution {
  public:
    int reverse(int x) {
        // sign
        long long int abs = x;
        bool pos = true;
        if (x < 0) {
            abs *= -1;
            pos = false;
        }

        // reverse
        long long int ans = 0;
        while (abs > 0) {
            ans *= 10;
            ans += abs % 10;
            abs /= 10;
        }

        // bounds
        if (ans < INT_MIN || INT_MAX < ans) {
            return 0;
        }

        return pos ? ans : -ans;
    }
};