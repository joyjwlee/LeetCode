class Solution {
  public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        // variables
        int dx, dy, ndx, ndy;

        // original dx dy
        dx = coordinates[1][0] - coordinates[0][0];
        dy = coordinates[1][1] - coordinates[0][1];

        // loop through and return
        for (int i = 0; i < coordinates.size(); i++) {
            // get new dx dy
            ndx = coordinates[i][0] - coordinates[0][0];
            ndy = coordinates[i][1] - coordinates[0][1];
            // return false if not same
            if (ndx * dy != ndy * dx)
                return false;
        }
        return true;
    }
};