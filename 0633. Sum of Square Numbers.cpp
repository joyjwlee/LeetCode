class Solution {
  public:
    bool judgeSquareSum(int c) {
        // edge
        if (c == 0)
            return true;

        // two pointer
        long int left = 0, right = sqrt(c);
        while (left <= right) {
            long int sum = left * left + right * right;
            if (sum == c)
                return true;
            else if (sum > c)
                right--;
            else
                left++;
        }
        return false;
    }
};