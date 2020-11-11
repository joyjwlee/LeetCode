class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        // 2 maps for pairing
        unordered_map<char, char> sMap, tMap;

        // loop through s and t
        for (int i = 0; i < s.size(); i++) {
            // if not found
            if (sMap.find(s[i]) == sMap.end() && tMap.find(t[i]) == tMap.end()) {
                sMap[s[i]] = t[i];
                tMap[t[i]] = s[i];
            }

            // otherwise check if same
            else {
                if (sMap.find(s[i]) != sMap.end() && sMap[s[i]] != t[i])
                    return false;
                if (tMap.find(t[i]) != tMap.end() && tMap[t[i]] != s[i])
                    return false;
            }
        }

        return true;
    }
};