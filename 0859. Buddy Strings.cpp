class Solution {
  public:
    bool buddyStrings(string A, string B) {
        // edge
        if (A.size() != B.size())
            return false;

        // loop through
        int diff, first = -1, second = -1;
        unordered_set<char> letters;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                diff++;
                if (first == -1)
                    first = i;
                else if (second == -1)
                    second = i;
                else
                    return false; // more than 2 diff
            }
            // keep track for identical
            letters.insert(A[i]);
        }

        // if 2 places diff
        if (first != -1 && second != -1)
            return A[first] == B[second] && A[second] == B[first];

        // if only 1
        if (first != -1)
            return false;

        // otherwise see if duplicate letters
        return letters.size() < A.size();
    }
};