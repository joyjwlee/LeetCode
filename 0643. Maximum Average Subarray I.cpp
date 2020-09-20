class Solution {
  public:
    double findMaxAverage(vector<int> &nums, int k) {
        // init sliding window
        double window = 0;
        for (int i = 0; i < k; i++)
            window += nums[i];

        // loop through, updating max
        double max = window;
        for (int i = k; i < nums.size(); i++) {
            window += nums[i];
            window -= nums[i - k];
            if (window > max)
                max = window;
        }
        return max / k;
    }
};