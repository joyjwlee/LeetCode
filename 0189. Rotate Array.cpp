class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        // reduce
        k %= nums.size();
        // get last k
        vector<int> ans(nums.end() - k, nums.end());
        // put first size-k
        ans.insert(ans.end(), nums.begin(), nums.end() - k);
        nums = ans;
    }
};