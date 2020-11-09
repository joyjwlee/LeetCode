class Solution {
  public:
    int repeatedNTimes(vector<int> &A) {
        // map, keep track
        unordered_map<int, int> mp;
        for (int i = 0; i < A.size(); i++)
            mp[A[i]]++;

        // loop through and return
        for (auto i : mp)
            if (i.second == A.size() / 2)
                return i.first;
        return 0;
    }
};