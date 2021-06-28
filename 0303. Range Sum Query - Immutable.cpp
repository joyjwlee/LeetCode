class NumArray {
  public:
    vector<int> psum;

    NumArray(vector<int> &nums) {
        psum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
            psum.push_back(nums[i] + psum[i - 1]);
    }

    int sumRange(int left, int right) {
        return (left == 0) ? psum[right] : psum[right] - psum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */