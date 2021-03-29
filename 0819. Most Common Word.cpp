class Solution {
  public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        // make lowercase
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);

        // init
        map<string, int> mp;
        string temp = "";
        bool notBanned = true;

        // split and count freq of all that isn't in banned
        for (char c : paragraph) {
            // if letter, add to temp string
            if (isalpha(c))
                temp += c;

            // otherwise add to map if not banned and reset
            else {
                if (temp.size() != 0) {
                    notBanned = true;
                    for (string s : banned)
                        if (temp == s) {
                            notBanned = false;
                            break;
                        }
                    if (notBanned)
                        mp[temp]++;
                    temp = "";
                }
            }
        }

        // run one more time
        if (temp.size() != 0) {
            notBanned = true;
            for (string s : banned)
                if (temp == s) {
                    notBanned = false;
                    break;
                }
            if (notBanned)
                mp[temp]++;
            temp = "";
        }

        // find highest and return
        string ans = "";
        int max = INT_MIN;
        for (auto i : mp) {
            if (i.second > max) {
                ans = i.first;
                max = i.second;
            }
        }
        return ans;
    }
};