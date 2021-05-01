class Solution {
  public:
    vector<string> summaryRanges(vector<int> &nums) {
        // init
        int n = nums.size();
        vector<string> ans;

        // edge
        if (n == 0)
            return ans;
        if (n == 1) {
            ans.push_back(to_string(nums[0]));
            return ans;
        }

        // loop thorugh
        int idx = 0;
        for (int i = 0; i < n - 1; i++) {
            // if diff not 1
            if (nums[i] + 1 != nums[i + 1]) {
                // add interval
                if (idx == i)
                    ans.push_back(to_string(nums[idx]));
                else
                    ans.push_back(to_string(nums[idx]) + "->" + to_string(nums[i]));
                // update idx
                idx = i + 1;
            }
        }

        // get last and return
        if (idx == n - 1)
            ans.push_back(to_string(nums[idx]));
        else
            ans.push_back(to_string(nums[idx]) + "->" + to_string(nums[n - 1]));
        return ans;
    }
};