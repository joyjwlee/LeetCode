class Solution {
  public:
    // helper to get max
    int getMax(int a, int b, int c) {
        if (a >= b && a >= c)
            return a;
        if (b >= a && b >= c)
            return b;
        return c;
    }

    // helper to get min
    int getMin(int a, int b, int c) {
        if (a <= b && a <= c)
            return a;
        if (b <= a && b <= c)
            return b;
        return c;
    }

    int maxProduct(vector<int> &nums) {
        // init -- prev and curr for simultaneous update
        int prevMin, prevMax, currMin, currMax, ans;
        prevMin = prevMax = currMin = currMax = ans = nums[0];

        // modified Kadane's
        for (int i = 1; i < nums.size(); i++) {
            // keep track of max and min --> for both pos and neg prod
            currMin = getMin(prevMax * nums[i], prevMin * nums[i], nums[i]);
            currMax = getMax(prevMax * nums[i], prevMin * nums[i], nums[i]);
            // update ans
            if (currMax > ans)
                ans = currMax;
            // update previous
            prevMin = currMin;
            prevMax = currMax;
        }
        return ans;
    }
};