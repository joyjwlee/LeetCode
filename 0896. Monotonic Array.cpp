class Solution {
  public:
    bool isMonotonic(vector<int> &A) {
        // edge
        if (A.size() <= 2)
            return true;

        // copy A without consecutive duplicates
        vector<int> noDuplicates;
        noDuplicates.push_back(A[0]);
        for (int i : A)
            if (i != noDuplicates[noDuplicates.size() - 1])
                noDuplicates.push_back(i);

        // find number of increases
        int increases = 0;
        for (int i = 0; i < noDuplicates.size() - 1; i++)
            if (noDuplicates[i] <= noDuplicates[i + 1])
                increases++;
        return increases == 0 || increases == noDuplicates.size() - 1;
    }
};