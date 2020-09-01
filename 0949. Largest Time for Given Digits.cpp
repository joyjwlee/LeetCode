class Solution {
  public:
    string largestTimeFromDigits(vector<int> &A) {
        // sort and init
        sort(A.begin(), A.end());
        string ans = "", temp = "";
        // just check all permutations
        do {
            // if it's a valid time
            if (A[0] * 10 + A[1] <= 23 && A[2] <= 5) {
                // create temp
                temp = to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
                // if temp is greater, update
                if (temp.compare(ans) > 0)
                    ans = temp;
            }
        } while (next_permutation(A.begin(), A.end()));
        return ans;
    }
};