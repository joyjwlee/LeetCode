class Solution {
  public:
    bool isBoomerang(vector<vector<int>> &points) {
        /*
        // do shoelace; if area is 0, then colinear
        vector<int> a = points[0], b = points[1], c = points[2];
        // return
        return (a[0]*b[1]+b[0]*c[1]+c[0]*a[1]) - (a[1]*b[0]+b[1]*c[0]+c[1]*a[0]);
        */

        // one liner of above
        return (points[0][0] * points[1][1] + points[1][0] * points[2][1] + points[2][0] * points[0][1]) - (points[0][1] * points[1][0] + points[1][1] * points[2][0] + points[2][1] * points[0][0]);
    }
};