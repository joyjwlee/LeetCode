class Solution {
  public:
    // true if C works
    bool works(vector<int> &weights, int D, int C) {
        int days = 1, w = 0;
        for (int i = 0; i < weights.size(); i++) {
            w += weights[i];
            // if too heavy, wait
            if (w > C) {
                days++;
                w = weights[i];
                // cannot ship within time, false
                if (days > D)
                    return false;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int> &weights, int D) {
        // get left and right bounds
        int left = 0, right = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > left)
                left = weights[i];
            right += weights[i];
        }

        // binary search the answer
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (works(weights, D, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};