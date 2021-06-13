class Solution {
  public:
    int getSum(int a, int b) {
        int n = a ^ b;
        int carry = a & b;
        return (carry == 0) ? n : getSum(n, (unsigned int)carry << 1);
    }
};