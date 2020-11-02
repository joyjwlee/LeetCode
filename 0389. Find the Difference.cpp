class Solution {
  public:
    char findTheDifference(string s, string t) {
        // map for both
        unordered_map<char, int> mapS, mapT;

        // loop through
        for (char c : s)
            mapS[c]++;
        for (char c : t)
            mapT[c]++;

        // find which one is diff
        for (char i = 'a'; i <= 'z'; i++)
            if (mapS[i] != mapT[i])
                return i;
        return '.';
    }
};