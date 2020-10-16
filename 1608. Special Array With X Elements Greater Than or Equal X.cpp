class Solution {
  public:
    int specialArray(vector<int> &nums) {
        // keep track of count and loop
        int cnt = 0;
        for (int i = 0; i <= nums.size(); i++) {
            cnt = 0;
            for (int n : nums)
                if (n >= i)
                    cnt++;
            if (cnt == i)
                return i;
        }
        return -1;
    }
};