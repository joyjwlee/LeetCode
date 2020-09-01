class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        // combine the vectors and sort
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        // if odd size
        if (nums1.size() % 2 != 0)
            return nums1[nums1.size() / 2];
        // otherwise return avg of middle 2
        return (nums1[(nums1.size() - 1) / 2] + nums1[(nums1.size() + 1) / 2]) / 2.00;
    }
};