class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        // two pointer solution
        int n = nums.size(), left = 0, right = 0, temp;
        // rearrange
        while (right < n) {
            // if we see zero, move right
            if (nums[right] == 0)
                right++;
            // otherwise, swap both and move both
            else {
                temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++, right++;
            }
        }
    }
};