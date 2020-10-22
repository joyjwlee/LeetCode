class Solution {
  public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        // get psum
        vector<int> psum = arr;
        for (int i = 1; i < psum.size(); i++)
            psum[i] += psum[i - 1];

        // generate all odd lengths, add to sum
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
            for (int j = i; j < arr.size(); j += 2)
                ans += psum[j] - psum[i] + arr[i];
        return ans;
    }
};