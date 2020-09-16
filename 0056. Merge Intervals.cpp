class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        // edge
        if (intervals.size() == 0)
            return intervals;

        // init
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        // loop through, O(n)
        vector<int> temp = intervals[0];
        for (vector<int> curr : intervals) {
            // new is after, so just add interval to answer
            if (curr[1] < temp[0]) {
                ans.push_back(curr);
            }
            // new is before, so add new and update
            else if (temp[1] < curr[0]) {
                ans.push_back(temp);
                temp = curr;
            }
            // new overlaps, so choose min for start, max for end
            else if (temp[0] <= curr[1] || curr[0] <= temp[1]) {
                if (curr[0] < temp[0])
                    temp[0] = curr[0];
                if (curr[1] > temp[1])
                    temp[1] = curr[1];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};