class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        // create aux vector
        vector<int> v;

        // populate vector
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j])
                v.push_back(nums1[i++]);
            else
                v.push_back(nums2[j++]);
        }

        // get remaining
        while (i < m)
            v.push_back(nums1[i++]);
        while (j < n)
            v.push_back(nums2[j++]);

        // set
        nums1 = v;
    }
};