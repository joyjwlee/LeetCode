class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // simple binary search
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};