class Solution {
  public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right) {
        int n = 0;
        for (int i = left; i <= right; i++) {
            int n = 0;
            for (int j = 0; j < ranges.size(); j++)
                if (ranges[j][0] <= i && i <= ranges[j][1])
                    n++;
            if (n == 0)
                return false;
        }
        return true;
    }
};