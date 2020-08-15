class Solution {
  public:
    bool isPowerOfTwo(int n) {
        // edge
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        // loop through the number
        while (n > 2) {
            if (n % 2 == 1)
                return false;
            n /= 2;
        }
        return true;
    }
};