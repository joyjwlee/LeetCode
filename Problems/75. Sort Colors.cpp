class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int i = 0, j = nums.size() - 1, x = 0;
        while (x <= j) {
            if (nums[x] == 0) {
                swap(nums[x++], nums[i++]);
            } else if (nums[x] == 2) {
                swap(nums[j--], nums[x]);
            } else {
                x++;
            }
        }
        return;
    }
};