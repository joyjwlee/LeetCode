class Solution {
  public:
    // helper function
    int val(char c) {
        if (c == 'I')
            return 1;
        else if (c == 'V')
            return 5;
        else if (c == 'X')
            return 10;
        else if (c == 'L')
            return 50;
        else if (c == 'C')
            return 100;
        else if (c == 'D')
            return 500;
        return 1000;
    }

    int romanToInt(string s) {
        // iterate through, get answer
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            // if decrementing
            if ((i + 1 < s.size()) && (val(s[i]) < val(s[i + 1]))) {
                ans += (val(s[i + 1]) - val(s[i]));
                i++;
            } else {
                ans += val(s[i]);
            }
        }

        return ans;
    }
};