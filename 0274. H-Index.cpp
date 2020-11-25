class Solution {
  public:
    bool works(int pot, vector<int> &citations) {
        int cnt = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= pot) {
                cnt++;
            }
        }
        return cnt >= pot;
    }

    int hIndex(vector<int> &citations) {
        // binary search
        int l = 0, r = citations.size(), m;
        while (l < r) {
            m = l + (r - l + 1) / 2;
            if (works(m, citations)) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};