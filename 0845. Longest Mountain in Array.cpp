class Solution {
  public:
    int longestMountain(vector<int> &A) {
        if (A.size() < 3)
            return 0;

        // variables
        int ans = 0, temp, l, r;

        // find peak and go left and right
        for (int i = 1; i < A.size() - 1; i++) {
            // if is peak
            if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
                // go down both ways
                temp = 3, l = i - 1, r = i + 1;

                // left
                while (0 < l) {
                    if (A[l - 1] < A[l]) {
                        l--;
                        temp++;
                    } else {
                        break;
                    }
                }

                // right
                while (r < A.size() - 1) {
                    if (A[r] > A[r + 1]) {
                        r++;
                        temp++;
                    } else {
                        break;
                    }
                }

                // update
                if (temp > ans)
                    ans = temp;
            }
        }
        return ans;
    }
};