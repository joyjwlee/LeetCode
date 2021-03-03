class Solution {
  public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        // variables
        map<string, pair<int, int>> idx; // map to keep track of indices (idx,visits)
        int min = 0x3f3f3f3f;            // keep track of min idx
        vector<string> ans;

        // loop through both lists
        for (int i = 0; i < list1.size(); i++) {
            idx[list1[i]].first += i;
            idx[list1[i]].second++;
        }
        for (int i = 0; i < list2.size(); i++) {
            idx[list2[i]].first += i;
            idx[list2[i]].second++;
            // if visited twice and smaller, udpate min
            min = (idx[list2[i]].second == 2 && idx[list2[i]].first < min) ? idx[list2[i]].first : min;
        }

        // loop through and return
        for (auto i : idx)
            if (i.second.first == min && i.second.second == 2)
                ans.push_back(i.first);
        return ans;
    }
};