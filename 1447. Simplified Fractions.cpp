class Solution {
  public:
    // Euclid's for GCF
    int getGCF(int a, int b) {
        if (a == 0)
            return b;
        return getGCF(b % a, a);
    }

    vector<string> simplifiedFractions(int n) {
        // init
        vector<string> ans;
        string s = "";

        // loop through numerator and denominator
        for (int denom = 2; denom <= n; denom++) {
            for (int numer = 1; numer < denom; numer++) {
                // if relatively prime i.e. GCF is 1
                if (getGCF(denom, numer) == 1) {
                    // make string, add to vector
                    s = to_string(numer);
                    s += '/';
                    s += to_string(denom);
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};