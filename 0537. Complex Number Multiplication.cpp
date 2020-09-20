class Solution {
  public:
    // helpers
    int getReals(string s) {
        int real = 0;
        bool isPos = true;

        // determine +/-
        int i = 0;
        if (s[0] == '-') {
            isPos = false;
            i++;
        }

        // get number and return
        while (i < s.size() && isdigit(s[i])) {
            real = real * 10 + (s[i] - '0');
            i++;
        }
        return isPos ? real : -real;
    }

    int getImaginaries(string s) {
        int imaginary = 0;
        bool isPos = true;

        // get to the start of num, det +/-
        int i = 0;
        while (i < s.size() && s[i] != '+')
            i++;
        if (s[i + 1] == '-') {
            isPos = false;
            i++;
        }

        // get number and return
        while (i + 1 < s.size() && isdigit(s[i + 1])) {
            imaginary = imaginary * 10 + (s[i + 1] - '0');
            i++;
        }
        return isPos ? imaginary : -imaginary;
    }

    string complexNumberMultiply(string a, string b) {
        // get reals and imaginaries
        int aR = getReals(a);
        int bR = getReals(b);
        int aI = getImaginaries(a);
        int bI = getImaginaries(b);

        // do calculations
        int ansR = aR * bR - aI * bI;
        int ansI = aR * bI + bR * aI;

        // concatenate and return
        string ans = to_string(ansR);
        ans += "+";
        ans += to_string(ansI);
        ans += "i";
        return ans;
    }
};