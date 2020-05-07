class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if (x == 1)
            return 1;
        if (x == -1)
            return n % 2 ? -1 : 1;
        long order = 1, rem = 0;
        if (n > 0)
            ans *= x;
        if (n < 0)
            ans = ans / x;
        long m = n;
        m = abs(m);
        while (m / (order * 2)) {
            ans *= ans;
            order *= 2;
        }
        rem = m - order;
        for (int i = 0; i < rem; i++) {
            if (n > 0)
                ans *= x;
            if (n < 0)
                ans = ans / x;
        }
        return ans;
    }
};