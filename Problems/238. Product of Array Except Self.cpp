class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int product = 1;
        int zeroes = 0;
        int n = nums.size();
        for (auto x : nums) {
            if (x == 0)
                zeroes++;
            else
                product *= x;
        }

        vector<int> ans;
        if (zeroes == 0) {
            vector<int> ans(n, 1);
            for (int i = 1; i < n; i++) {
                ans[i] = ans[i - 1] * nums[i - 1];
            }
            int p = 1;
            for (int i = n - 2; i >= 0; i--) {
                p *= nums[i + 1];
                ans[i] *= p;
            }
            return ans;
        } if (zeroes == 1) {
            for (auto x : nums) {
                if (x == 0)
                    ans.push_back(product);
                else
                    ans.push_back(0);
            }
            return ans;
        }
        return vector<int>(n, 0);
    }
};