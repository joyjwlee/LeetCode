class Solution {
  public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
        int ans = 0, dx, dy;
        for (int i = 0; i < points.size() - 1; i++) {
            dx = abs(points[i][0] - points[i + 1][0]);
            dy = abs(points[i][1] - points[i + 1][1]);
            ans += abs(dx - dy) + min(dx, dy);
        }
        return ans;
    }
};