class Solution {
  public:
    bool works(string s, string str) {
        // loop through both
        int idxS = 0, idxStr = 0;
        while (idxS < s.size() && idxStr < str.size()) {
            // if same characters, move both
            if (s[idxS] == str[idxStr]) {
                idxS++;
                idxStr++;
            }
            // otherwise move just idxS
            else
                idxS++;
        }

        // true if str's index reaches end
        return str.size() == idxStr;
    }

    string findLongestWord(string s, vector<string> &d) {
        string ans = "";
        // loop through all and return answer
        for (string str : d) {
            // if string works
            if (works(s, str)) {
                // if greater, just update
                if (str.size() > ans.size())
                    ans = str;
                // if same, lexicographically smaller
                else if (str.size() == ans.size() && str < ans)
                    ans = str;
            }
        }
        return ans;
    }
};