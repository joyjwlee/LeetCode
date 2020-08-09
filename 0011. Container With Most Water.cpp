class Solution {
  public:
    int maxArea(vector<int> &height) {
        int max = 0, l = 0, r = height.size() - 1, min;
        // 2 pointer solution
        while (l < r) {
            // update max
            min = (height[l] < height[r]) ? height[l] : height[r];
            if (min * (r - l) > max)
                max = min * (r - l);
            // update pointer
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return max;
    }
};