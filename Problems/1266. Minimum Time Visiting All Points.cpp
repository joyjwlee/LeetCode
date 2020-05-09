class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
        int ans = 0;
        int x1, y1, x2, y2, dx, dy;
        for (int i = 0; i < points.size() - 1; i++) {
            x1 = points[i][0];
            y1 = points[i][1];
            x2 = points[i + 1][0];
            y2 = points[i + 1][1];
            dx = abs(x1 - x2);
            dy = abs(y1 - y2);
            ans += max(dx, dy);
        }
        return ans;
    }
};