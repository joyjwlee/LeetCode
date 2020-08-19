class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        // edge
        if (nums.size() == 0)
            return 0;

        // two pointer solution
        int p1 = 0;
        for (int p2 = 1; p2 < nums.size(); p2++) {
            // if we find a unique
            if (nums[p1] != nums[p2]) {
                // advance pointer 1
                p1++;
                // replace with pointer 2
                nums[p1] = nums[p2];
            }
        }
        // return size
        return p1 + 1;
    }
};