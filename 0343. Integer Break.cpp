class Solution {
  public:
    int integerBreak(int n) {
        // edge
        if (n <= 3)
            return n - 1;

        // find and return
        if (n % 3 == 0)
            return pow(3, n / 3) * pow(2, 0);
        if (n % 3 == 1)
            return pow(3, n / 3 - 1) * pow(2, 2);
        return pow(3, n / 3) * pow(2, 1);
    }
};

/*
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
*/