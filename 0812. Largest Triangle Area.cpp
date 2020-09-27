class Solution {
  public:
    // get area using shoelace
    double getArea(vector<int> &p1, vector<int> &p2, vector<int> &p3) {
        double a = p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1];
        double b = p1[1] * p2[0] + p2[1] * p3[0] + p3[1] * p1[0];
        double area = (1 / 2.0) * (a - b);
        return (area >= 0) ? area : -area;
    }

    double largestTriangleArea(vector<vector<int>> &points) {
        // brute force O(n^3)
        double ans = INT_MIN, temp;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    temp = getArea(points[i], points[j], points[k]);
                    if (temp > ans)
                        ans = temp;
                }
            }
        }
        return ans;
    }
};