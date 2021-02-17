class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        // enumerate set
        set<int> s;
        for (int n : nums)
            s.insert(n);

        // create and return ans
        vector<int> ans;
        for (int i = 1; i <= nums.size(); i++) {
            if (s.find(i) == s.end())
                ans.push_back(i);
        }
        return ans;
    }
};