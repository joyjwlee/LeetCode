class Solution {
  public:
    bool isPowerOfFour(int num) {
        // edge
        if (num == 1)
            return true;
        if (num <= 3)
            return false;

        // loop and return
        while (num > 4) {
            if (num % 4 != 0)
                return false;
            num /= 4;
        }
        return num == 4;
    }
};