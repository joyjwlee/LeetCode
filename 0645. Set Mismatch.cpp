class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        // vars
        vector<int> ans;
        // get frequency of all
        map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
            if (freq[n] == 2)
                ans.push_back(n);
        }
        // get missing and return
        for (int i = 1; i <= nums.size(); i++) {
            if (freq[i] == 0) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};