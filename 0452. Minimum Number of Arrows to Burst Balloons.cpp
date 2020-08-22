class Solution {
  public:
    int findMinArrowShots(vector<vector<int>> &points) {
        // edge
        if (points.size() == 0)
            return 0;

        // sort increasing order by end point
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        // loop through with greedy
        int ans = 0;
        int furthest = points[0][1];
        for (int i = 0; i < points.size(); i++) {
            // if we are at a balloon we haven't popped yet, pop it
            if (points[i][0] > furthest) {
                ans++;
                furthest = points[i][1];
            }
        }

        return ans + 1;
    }
};