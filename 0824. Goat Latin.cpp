class Solution {
  public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }

    string toGoatLatin(string S) {
        // split string into components
        vector<string> words;
        string str = "";
        for (auto c : S) {
            // space, then add and reset
            if (c == ' ') {
                words.push_back(str);
                str = "";
            } else {
                str += c;
            }
        }
        // get last word
        words.push_back(str);

        // convert to goat latin
        for (int i = 0; i < words.size(); i++) {
            // vowel or consonant
            if (!isVowel(words[i][0])) {
                words[i] += words[i][0];
                words[i] = words[i].substr(1, words[i].size());
            }
            words[i] += "ma";
            // append a
            for (int j = 0; j <= i; j++)
                words[i] += 'a';
        }

        // combine together
        str = "";
        for (string s : words)
            str += (s + ' ');

        // remove last space and return
        return str.substr(0, str.size() - 1);
    }
};