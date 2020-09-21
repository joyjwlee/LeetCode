class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        // sort both
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // two pointers
        vector<int> ans;
        int one = 0, two = 0;
        while (one < nums1.size() && two < nums2.size()) {
            if (nums1[one] > nums2[two])
                two++;
            else if (nums1[one] < nums2[two])
                one++;
            else {
                ans.push_back(nums1[one]);
                one++;
                two++;
            }
        }
        return ans;
    }
};