class Solution {
  public:
    int longestOnes(vector<int> &A, int K) {
        int max = 0, left = 0, zeros = 0;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] == 0)
                zeros++;

            // zeros greater than K, move left pointer
            if (zeros > K)
                while (zeros > K && left <= i)
                    if (A[left++] == 0)
                        zeros--;

            // get size, update max
            if (i - left + 1 > max)
                max = i - left + 1;
        }

        return max;
    }
};