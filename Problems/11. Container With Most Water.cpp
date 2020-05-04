class Solution {
public:
    int maxArea(vector<int> &height) {
        int maximum = 0;
        int first = 0;
        int last = height.size() - 1;

        while (first < last) {
            maximum = max((min(height[first], height[last]) * (last - first)), maximum);
            if (height[first] < height[last])
                first++;
            else
                last--;
        }

        return maximum;
  }
};