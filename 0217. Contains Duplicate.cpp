class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        // sort array
        sort(nums.begin(), nums.end());
        // loop through
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                return true;
        return false;
    }
};