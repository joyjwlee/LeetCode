class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        // init
        vector<vector<int>> ans;

        // use bit manipulation (32) to generate subset
        int bits;
        for (int i = 0; i < pow(2, nums.size()); i++) {
            vector<int> v;
            bits = 1;
            for (int j = 0; j < 31; j++) {
                if (bits & i)
                    v.push_back(nums[j]);
                bits = bits << 1;
            }
            ans.push_back(v);
        }
        return ans;
    }
};