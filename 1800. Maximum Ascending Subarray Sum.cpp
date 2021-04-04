class Solution {
  public:
    int maxAscendingSum(vector<int> &nums) {
        // find indices
        vector<int> idx;
        idx.push_back(0);
        for (int i = 1; i < nums.size(); i++)
            if (nums[i - 1] >= nums[i])
                idx.push_back(i);
        idx.push_back(nums.size());

        // make psum
        nums.insert(nums.begin(), 0);
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];

        // find ans and return
        int ans = 0;
        for (int i = 1; i < idx.size(); i++)
            if (nums[idx[i]] - nums[idx[i - 1]] > ans)
                ans = nums[idx[i]] - nums[idx[i - 1]];
        return ans;
    }
};