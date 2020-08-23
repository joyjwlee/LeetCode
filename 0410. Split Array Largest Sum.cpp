class Solution {
  public:
    int contigNeeded(vector<int> &nums, int mid) {
        int cnt = 1, sub = 0;
        for (int n : nums) {
            // if smaller, add
            if (sub + n <= mid) {
                sub += n;
            } else {
                sub = n;
                cnt++;
            }
        }
        return cnt;
    }

    int splitArray(vector<int> &nums, int m) {
        // get left and right search spaces
        int left = -0x3f3f3f3f, right = 0, mid;
        for (int n : nums) {
            if (n > left)
                left = n;
            right += n;
        }

        // binary search the sum
        while (left < right) {
            mid = left + (right - left) / 2;
            if (contigNeeded(nums, mid) <= m)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};