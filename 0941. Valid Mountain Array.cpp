class Solution {
  public:
    bool validMountainArray(vector<int> &arr) {
        // edge
        if (arr.size() <= 2)
            return false;

        // find peak
        int idx = 0;
        int max = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
                idx = i;
            }
        }

        // if peak at beginning or end
        if (idx == 0 || idx == arr.size() - 1)
            return false;

        // check if monotonic in each direction
        for (int i = idx; i >= 1; i--)
            if (arr[i - 1] >= arr[i])
                return false;
        for (int i = idx; i < arr.size() - 1; i++)
            if (arr[i] <= arr[i + 1])
                return false;
        return true;
    }
};