class Solution {
  public:
    int atMostNGivenDigitSet(vector<string> &digits, int n) {
        // variables
        set<string> s;
        vector<string> curr;
        bool createdNew;
        string temp;

        // initialize set
        for (int i = 0; i < digits.size(); i++)
            if (stoi(digits[i]) <= n)
                s.insert(digits[i]);

        // dp through, generate, and return
        for (int test = 0; test < 10; test++) {
            // reset all values
            createdNew = false;
            curr.clear();

            // extract curr in stack
            for (auto itr = s.begin(); itr != s.end(); itr++)
                curr.push_back(*itr);

            // loop through all in digits
            for (int i = 0; i < digits.size(); i++) {
                // loop through all in curr
                for (int j = 0; j < curr.size(); j++) {
                    // add front
                    temp = curr[j] + digits[i];
                    if (stol(temp) <= n) {
                        s.insert(temp);
                        createdNew = true;
                    }
                    // temp2, add back
                    temp = digits[i] + curr[j];
                    if (stol(temp) <= n) {
                        s.insert(temp);
                        createdNew = true;
                    }
                }
            }
        }

        // return size of set
        return s.size();
    }
};