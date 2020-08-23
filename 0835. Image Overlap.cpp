class Solution {
  public:
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B) {
        int n = A.size(), ans = 0, temp;
        // brute force loop through
        // keep A, move B
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // reset temp
                temp = 0;
                // calculate temp
                for (int k = i; k < n; k++)
                    for (int l = j; l < n; l++)
                        if (A[k][l] == 1 && A[k][l] == B[k - i][l - j])
                            temp++;
                // update ans
                if (temp > ans)
                    ans = temp;
            }
        }
        // keep B, move A
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // reset temp
                temp = 0;
                // calculate temp
                for (int k = i; k < n; k++)
                    for (int l = j; l < n; l++)
                        if (B[k][l] == 1 && B[k][l] == A[k - i][l - j])
                            temp++;
                // update ans
                if (temp > ans)
                    ans = temp;
            }
        }
        return ans;
    }
};