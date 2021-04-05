class Solution {
  public:
    string removeLeadingZero(string s) {
        int idx = 0;
        while (idx < s.size() && s[idx] == '0')
            idx++;
        if (idx == s.size())
            return "0";
        return s.substr(idx);
    }

    int numDifferentIntegers(string word) {
        // init
        set<string> s;
        string temp = "";

        // loop through
        for (int i = 0; i < word.size(); i++) {
            if (isdigit(word[i]))
                temp += word[i];
            else {
                if (temp.size() != 0) {
                    temp = removeLeadingZero(temp);
                    s.insert(temp);
                    temp = "";
                }
            }
        }

        // one more time
        if (temp.size() != 0) {
            temp = removeLeadingZero(temp);
            s.insert(temp);
        }

        // return num of unique
        return s.size();
    }
};