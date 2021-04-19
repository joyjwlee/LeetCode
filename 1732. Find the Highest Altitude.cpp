class Solution {
  public:
    int largestAltitude(vector<int> &gain) {
        int ans = 0;
        int psum = 0;
        for (int i : gain) {
            psum += i;
            if (psum > ans)
                ans = psum;
        }
        return ans;
    }
};