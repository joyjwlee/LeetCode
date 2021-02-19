class Solution {
  public:
    int numberOfArithmeticSlices(vector<int> &A) {
        // edge
        if (A.size() <= 2)
            return 0;

        // create vector of differences
        vector<int> diffs;
        for (int i = 0; i < A.size() - 1; i++)
            diffs.push_back(A[i + 1] - A[i]);

        // create vector of sizes of sequences
        vector<int> sizes;
        int n = 2; // 2 since that's min number for arithmetic sequence
        for (int i = 0; i < diffs.size() - 1; i++) {
            // if same, increase size
            if (diffs[i + 1] == diffs[i]) {
                n++;
            }
            // otherwise add and reset
            else {
                sizes.push_back(n);
                n = 2;
            }
        }
        // don't forget last n
        sizes.push_back(n);

        // calculate and return answer
        int ans = 0;
        for (int n : sizes) {
            if (n >= 3) {
                for (int i = 3; i <= n; i++)
                    ans += n - i + 1;
            }
        }
        return ans;
    }
};