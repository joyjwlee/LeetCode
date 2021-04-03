class Solution {
  public:
    vector<string> commonChars(vector<string> &A) {
        // get chars that show up in all
        vector<char> common;
        int freq, temp;
        for (char c = 'a'; c <= 'z'; c++) {
            freq = 0;
            for (string s : A)
                if (s.find(c) != -1)
                    freq++;
            if (freq == A.size())
                common.push_back(c);
        }

        // now get min freq of each in all words
        vector<string> ans;
        for (char c : common) {
            freq = INT_MAX;
            for (string s : A) {
                temp = 0;
                for (char ch : s) {
                    if (c == ch) {
                        temp++;
                    }
                }
                if (temp < freq)
                    freq = temp;
            }

            for (int i = 0; i < freq; i++) {
                string s(1, c);
                ans.push_back(s);
            }
        }
        return ans;
    }
};