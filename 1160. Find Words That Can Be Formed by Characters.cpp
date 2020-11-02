class Solution {
  public:
    int countCharacters(vector<string> &words, string chars) {
        // get freq for chars
        vector<int> avail(30);
        for (char c : chars)
            avail[c - 'a']++;

        // loop through each word, get ans, and return
        int ans = 0;
        vector<int> freq(30);
        bool isGood = true;
        for (string word : words) {
            // reset to 0
            fill(freq.begin(), freq.end(), 0);
            // reset to true
            isGood = true;
            // get freq from word
            for (char c : word)
                freq[c - 'a']++;
            // see if good or not
            for (int i = 0; i < 26; i++)
                if (freq[i] > avail[i])
                    isGood = false;
            // if good, add to ans
            if (isGood) {
                ans += word.size();
                cout << word << endl;
            }
        }
        return ans;
    }
};