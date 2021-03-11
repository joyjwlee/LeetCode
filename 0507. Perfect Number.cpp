class Solution {
  public:
    bool checkPerfectNumber(int num) {
        // edge
        if (num == 1)
            return false;

        // get sum of divisors (set 1 for 1)
        int sumOfDivisors = 1;
        // only need to go up to square root
        for (int i = 2; i * i <= num; i++) {
            // if divisor
            if (num % i == 0) {
                // if square
                if (i * i == num)
                    sumOfDivisors += i;
                // otherwise add both
                else {
                    sumOfDivisors += i;
                    sumOfDivisors += num / i;
                }
            }
        }
        return sumOfDivisors == num;
    }
};