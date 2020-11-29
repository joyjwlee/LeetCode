class Solution {
  public:
    // helper to see if self dividing or not
    bool works(int i) {
        int n = i;
        while (n) {
            if (n % 10 == 0)
                return false;
            if (i % (n % 10) != 0)
                return false;
            n /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        // brute force and return
        vector<int> ans;
        for (int i = left; i <= right; i++)
            if (works(i))
                ans.push_back(i);
        return ans;
    }
};