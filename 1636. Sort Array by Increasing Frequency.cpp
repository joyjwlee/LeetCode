class Solution {
  public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        // if same freq, return descending
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }

    vector<int> frequencySort(vector<int> &nums) {
        // get frequencies
        unordered_map<int, int> freq;
        for (int n : nums)
            freq[n]++;

        // put into vector and sort
        vector<pair<int, int>> vec;
        for (auto itr : freq)
            vec.push_back({itr.first, itr.second});
        sort(vec.begin(), vec.end(), cmp);

        // put into int vector and return
        vector<int> ans;
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].second; j++) {
                ans.push_back(vec[i].first);
            }
        }
        return ans;
    }
};