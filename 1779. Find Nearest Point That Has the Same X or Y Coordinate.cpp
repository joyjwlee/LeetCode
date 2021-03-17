class Solution {
  public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
        // init
        int ans = -1, dist = INT_MAX, temp;
        // loop through all points
        for (int i = 0; i < points.size(); i++) {
            // if same x or y
            if (points[i][0] == x || points[i][1] == y) {
                temp = abs(points[i][0] - x + points[i][1] - y);
                if (temp < dist) {
                    dist = temp;
                    ans = i;
                }
            }
        }
        // return
        return ans;
    }
};