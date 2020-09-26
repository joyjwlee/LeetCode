class Solution {
  public:
    string reformatDate(string date) {
        // parse input
        vector<string> d;
        stringstream s(date);
        string word;
        while (s >> word)
            d.push_back(word);

        // get year
        string ans = d[2];

        // get month
        string months[] = {"zeroIdx", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (int i = 0; i <= 12; i++) {
            if (months[i] == d[1]) {
                ans += "-";
                // if less than 10
                if (i < 10)
                    ans += "0";
                ans += to_string(i) + "-";
                break;
            }
        }

        // get day
        if (isdigit(d[0][1])) {
            ans += d[0][0];
            ans += d[0][1];
        } else {
            ans += "0";
            ans += d[0][0];
        }

        // return
        return ans;
    }
};