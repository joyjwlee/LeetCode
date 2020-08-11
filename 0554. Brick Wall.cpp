class Solution {
  public:
    int leastBricks(vector<vector<int>> &wall) {
        // map to keep track of ending pos
        unordered_map<int, int> mp;
        int pos = 0, max = 0;
        // map ends
        for (int i = 0; i < wall.size(); i++) {
            pos = 0;
            // don't go to last edge
            for (int j = 0; j < wall[i].size() - 1; j++) {
                pos += wall[i][j];
                mp[pos]++;
                // update max
                if (mp[pos] > max)
                    max = mp[pos];
            }
        }

        // minimum cuts is layers - most edges
        return wall.size() - max;
    }
};