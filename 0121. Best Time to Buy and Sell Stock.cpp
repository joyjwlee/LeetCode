class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // ans = highestPeakInFuture - lowestValleySoFar

        // init
        vector<int> valleys, peaks;
        const int size = prices.size();
        int ans = 0, min = INT_MAX, max = INT_MIN;

        // get mins so far
        for (int n : prices) {
            // update min
            if (n < min)
                min = n;
            // push
            valleys.push_back(min);
        }

        // reverse and get max so far
        reverse(prices.begin(), prices.end());
        for (int n : prices) {
            // update min
            if (n > max)
                max = n;
            // push
            peaks.push_back(max);
        }

        // loop through, calculate, and return
        for (int i = 0; i < size; i++)
            if (peaks[size - i - 1] - valleys[i] > ans)
                ans = peaks[size - i - 1] - valleys[i];
        return ans;
    }
};