class Solution {
  public:
    bool rotateString(string A, string B) {
        // compare right away
        if (A.compare(B) == 0)
            return true;

        // loop through all rotations
        for (int i = 0; i < A.size(); i++) {
            // rotate A
            A += A[0];
            A = A.substr(1);
            // compare
            if (A.compare(B) == 0)
                return true;
        }
        return false;
    }
};