class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0)
        return false;
    else {
        long long n, digit, rev = 0;
        n = x;
        do {
            digit = x % 10;
            rev = (rev * 10) + digit;
            x = x / 10;
        } while (x != 0);
        if (rev == n)
            return true;
        return false;
    }
  }
};