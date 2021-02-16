class Solution {
  public:
    vector<string> letterCasePermutation(string S) {
        // variables
        vector<string> gen, ans;
        gen.push_back("");

        // loop through each char and generate all
        for (char c : S) {
            int n = gen.size();
            for (int i = 0; i < n; i++) {
                gen.push_back(gen[i] + c);
                // add upper if lower
                if ('a' <= c && c <= 'z') {
                    gen.push_back(gen[i] + (char)(c - 32));
                }
                // add lower if upper
                else if ('A' <= c && c <= 'Z') {
                    gen.push_back(gen[i] + (char)(c + 32));
                }
            }
        }

        // only get strings of same length and return
        for (string s : gen)
            if (s.size() == S.size())
                ans.push_back(s);
        return ans;
    }
};