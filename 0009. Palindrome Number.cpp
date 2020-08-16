class Solution {
  public:
    bool isPalindrome(int x) {
        // edge
        if (x < 0)
            return false;

        // test
        long int rev = 0, temp = x;
        while (temp) {
            rev *= 10;
            rev += temp % 10;
            temp /= 10;
        }
        return rev == x;
    }
};