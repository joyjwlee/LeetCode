class Solution {
  public:
    int numSub(string s) {
        // get lengths of continuous 1s
        vector<int> ones;
        int len = 0;
        for (char c : s) {
            if (c == '1')
                len++;
            else {
                if (len != 0)
                    ones.push_back(len);
                len = 0;
            }
        }
        if (len != 0)
            ones.push_back(len);

        // calculate and return ans
        long int ans = 0, temp;
        for (int i : ones) {
            if (i % 2 == 0) {
                temp = i / 2;
                temp *= i + 1;
            } else {
                temp = (i + 1) / 2;
                temp *= i;
            }
            ans += temp;
            ans %= 1000000007;
        }
        return ans;
    }
};