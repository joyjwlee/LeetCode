class Solution {
  public:
    bool isPowerOfThree(int n) {
        // just multiply, use long
        long check = 1;
        while (check < n)
            check *= 3;
        return check == n;
    }
};