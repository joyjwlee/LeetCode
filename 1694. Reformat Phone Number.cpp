class Solution {
  public:
    string reformatNumber(string number) {
        if (number.size() <= 3)
            return number;

        // get numbers only
        string numOnly = "";
        for (char c : number)
            if (isdigit(c))
                numOnly += c;

        // make answer and return
        string ans = "";
        int i = 0;
        while (i < numOnly.size() - numOnly.size() % 3 - 3) {
            ans += numOnly[i];
            if ((i + 1) % 3 == 0)
                ans += '-';
            i++;
        }

        // last 3, 4, or 5 digits
        if (numOnly.size() - i == 3)
            ans += numOnly.substr(i, 3);
        else if (numOnly.size() - i == 4)
            ans += numOnly.substr(i, 2) + '-' + numOnly.substr(i + 2, 2);
        else
            ans += numOnly.substr(i, 3) + '-' + numOnly.substr(i + 3, 2);
        return ans;
    }
};