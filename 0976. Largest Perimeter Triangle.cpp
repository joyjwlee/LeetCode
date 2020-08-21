class Solution {
  public:
    int largestPerimeter(vector<int> &A) {
        if (A.size() < 3)
            return 0;
        // sort
        sort(A.begin(), A.end());
        // go from back
        for (int i = A.size() - 1; i >= 2; i--) {
            int a = A[i], b = A[i - 1], c = A[i - 2];
            if ((a + b) > c && (a + c) > b && (b + c) > a)
                return a + b + c;
        }
        return 0;
    }
};