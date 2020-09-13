class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        // answer vector to return
        vector<vector<int>> ans;

        // loop through, O(n)
        for (int i = 0; i < intervals.size(); i++) {
            // new is after, so just add interval to answer
            if (intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
            }
            // new is before, so add new and update
            else if (newInterval[1] < intervals[i][0]) {
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }
            // new overlaps, so choose min for start, max for end
            else if (newInterval[0] <= intervals[i][1] || intervals[i][0] <= newInterval[1]) {
                if (intervals[i][0] < newInterval[0])
                    newInterval[0] = intervals[i][0];
                if (intervals[i][1] > newInterval[1])
                    newInterval[1] = intervals[i][1];
            }
        }

        // add and return
        ans.push_back(newInterval);
        return ans;
    }
};