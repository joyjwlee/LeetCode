class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int ans = 0;
        for (int n : nums)
            if (n != val)
                nums[ans++] = n;
        return ans;
    }
};