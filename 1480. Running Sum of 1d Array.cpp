class Solution {
  public:
    vector<int> runningSum(vector<int> &nums) {
        // init
        vector<int> ans;
        int psum = 0;
        // loop
        for (int n : nums) {
            psum += n;
            ans.push_back(psum);
        }
        return ans;
    }
};