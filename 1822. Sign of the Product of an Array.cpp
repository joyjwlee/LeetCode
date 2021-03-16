class Solution {
  public:
    int arraySign(vector<int> &nums) {
        int numNeg = 0;
        for (int i : nums) {
            if (i == 0)
                return 0;
            else if (i < 0)
                numNeg++;
        }
        return (numNeg % 2 == 0) ? 1 : -1;
    }
};