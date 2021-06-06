class Solution {
  public:
    int stringToNum(string word) {
        string s = "";
        for (char c : word)
            s += c - ('a' - '0');
        return stoi(s);
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return stringToNum(firstWord) + stringToNum(secondWord) == stringToNum(targetWord);
    }
};