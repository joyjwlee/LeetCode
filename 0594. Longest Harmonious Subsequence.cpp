class Solution {
  public:
    int findLHS(vector<int> &nums) {
        // get frequencies of all
        map<int, int> freq;
        for (int i : nums)
            freq[i]++;

        // iterate and put into vector
        vector<pair<int, int>> vec;
        for (auto i : freq)
            vec.push_back(make_pair(i.first, i.second));

        // get answer and return
        int ans = 0, temp;
        for (int i = 0; i < vec.size() - 1; i++) {
            // if differ by one
            if (vec[i + 1].first - vec[i].first == 1) {
                // get temp
                temp = vec[i + 1].second + vec[i].second;
                // update ans if new max
                if (temp > ans)
                    ans = temp;
            }
        }
        return ans;
    }
};