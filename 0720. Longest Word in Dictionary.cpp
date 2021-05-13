class Solution {
  public:
    string longestWord(vector<string> &words) {
        // edge
        if (words.size() == 1)
            return words[0];

        // sort alphabetically
        sort(words.begin(), words.end());

        // init
        string ans = "";
        set<string> s;

        // loop through and return answer
        for (string str : words) {
            // insert to set directly is size is 1
            if (str.size() == 1) {
                s.insert(str);
                // update if necessary
                if (str.size() > ans.size())
                    ans = str;
            }
            // otherwise check if one before exists
            else if (s.find(str.substr(0, str.size() - 1)) != s.end()) {
                // insert to set
                s.insert(str);
                // update if necessary
                if (str.size() > ans.size())
                    ans = str;
            }
        }
        return ans;
    }
};