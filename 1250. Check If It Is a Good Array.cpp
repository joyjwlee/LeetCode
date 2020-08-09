class Solution {
  public:
    // Euclid's recursive
    int GCF(int n, int m) {
        if (m == 0)
            return n;
        return GCF(m, n % m);
    }

    bool isGoodArray(vector<int> &nums) {
        // edge
        if (!nums.size())
            return false;
        if (nums.size() == 1)
            return nums[0] == 1;
        // if GCF of entire array is 1, can make 1
        int n = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            n = GCF(n, nums[i]);
        }
        return n == 1;
    }
};