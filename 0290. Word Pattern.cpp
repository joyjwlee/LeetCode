class Solution {
  public:
    bool wordPattern(string pattern, string str) {
        // maps
        unordered_map<char, string> charMap;
        unordered_map<string, char> stringMap;

        // parse input
        stringstream s(str);
        string word;

        // variables
        int i = 0;
        char c;

        // iterate through each word
        while (s >> word) {
            if (i == pattern.size())
                return false;
            c = pattern[i];
            if (charMap.count(c) != stringMap.count(word))
                return false;
            // if already in the map
            if (charMap.count(c)) {
                // if not same, return false
                if ((charMap[c] != word) || (stringMap[word] != c))
                    return false;
            }
            // otherwise, add to map
            else {
                charMap[c] = word;
                stringMap[word] = c;
            }
            i++;
        }
        return i == pattern.size();
    }
};