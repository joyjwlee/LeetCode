class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        // XOR single sweep
        int ans = 0;
        for (int n : nums)
            ans ^= n;
        return ans;
    }
};