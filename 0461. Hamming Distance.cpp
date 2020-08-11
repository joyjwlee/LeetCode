class Solution {
  public:
    int hammingDistance(int x, int y) {
        // get XOR of 2 numbers
        int XOR = x ^ y;
        // count set bits
        int ans = 0;
        while (XOR) {
            ans += XOR & 1;
            XOR >>= 1;
        }
        return ans;
    }
};