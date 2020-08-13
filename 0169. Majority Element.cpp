class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        // umap
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        // find largest
        for (auto itr : mp)
            if (itr.second > nums.size() / 2)
                return itr.first;
        return 0;
    }
};