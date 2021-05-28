class Solution {
  public:
    int trap(vector<int> &height) {
        // edge
        if (height.size() <= 2)
            return 0;

        // init
        int n = height.size();
        int l = 0, r = n - 1;
        int maxLeft = height[0], maxRight = height[n - 1];

        // calc and return
        int ans = 0;
        while (l < r) {
            if (maxLeft < maxRight) {
                l++;
                maxLeft = max(maxLeft, height[l]);
                ans += maxLeft - height[l];
            } else {
                r--;
                maxRight = max(maxRight, height[r]);
                ans += maxRight - height[r];
            }
        }
        return ans;
    }
};

/*
// old solution
class Solution {
  public:
    int trap(vector<int> &height) {
        // edge
        if (height.size() <= 2)
            return 0;

        // init
        int n = height.size();
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);

        // calc maxLeft and maxRight
        int tempL = height[0], tempR = height[n - 1];
        for (int i = 1; i < n - 1; i++) {
            tempL = max(tempL, height[i]);
            tempR = max(tempR, height[n - i - 1]);
            maxLeft[i] = tempL;
            maxRight[n - i - 1] = tempR;
        }

        // calc and return
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
            ans += min(maxLeft[i], maxRight[i]) - height[i];
        return ans;
    }
};
*/

/*
notes/observations:
- single block/any 2 blocks cannot hold water -- [1, n-1)
- currVal = min(maxLeft, maxRight) - currHeight
- optimize from O(N^2) to O(N) by precalculating max vals
- time: O(N)
- space: O(N)
*/