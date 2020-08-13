class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        // edge case
        if (strs.size() == 0)
            return "";

        // find min length
        int min = INT_MAX;
        for (int i = 0; i < strs.size(); i++)
            if (strs[i].size() < min)
                min = strs[i].size();

        // loop through each word
        string ans = "";
        char c;
        bool isSame = true;
        // check ith char
        for (int i = 0; i < min; i++) {
            c = strs[0][i];
            isSame = true;
            // and go through each j words
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    isSame = false;
                    break;
                }
            }
            // if same add otherwise return
            if (isSame)
                ans += c;
            else
                return ans;
        }
        return ans;
    }
};