class Solution {
  public:
    int uniqueMorseRepresentations(vector<string> &words) {
        // init
        set<string> s;
        string str;
        string morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        // loop through each
        for (string word : words) {
            str = "";
            for (char c : word)
                str += morse[c - 'a'];
            s.insert(str);
        }

        // return size
        return s.size();
    }
};