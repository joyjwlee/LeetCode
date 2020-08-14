class Solution {
  public:
    // helper function 1
    int getDig(int n) {
        int cnt = 0;
        while (n != 0) {
            n /= 10;
            cnt++;
        }
        return cnt;
    }

    // helper function 2
    int getSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int addDigits(int num) {
        // edge
        if (num == 0)
            return 0;
        // calculate
        while (getDig(num) != 1)
            num = getSum(num);
        return num;
    }
};