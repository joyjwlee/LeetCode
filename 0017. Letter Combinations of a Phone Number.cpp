class Solution {
  public:
    vector<string> ans;
    map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    // helper method to generate recursively
    void generate(string digits, string s) {
        // base case
        if (digits.size() == s.size()) {
            ans.push_back(s);
            return;
        }
        // otherwise recurse
        char c = digits[s.size()];
        for (char append : mp[c])
            generate(digits, s + append);
    }

    vector<string> letterCombinations(string digits) {
        // edge
        if (digits.size() == 0)
            return ans;
        // otherwise generate
        generate(digits, "");
        return ans;
    }
};
