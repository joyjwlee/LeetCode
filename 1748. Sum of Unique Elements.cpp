class Solution {
  public:
    int sumOfUnique(vector<int> &nums) {
        // use a map
        map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        int ans = 0;
        for (auto i : mp)
            if (i.second == 1)
                ans += i.first;
        return ans;
    }
};