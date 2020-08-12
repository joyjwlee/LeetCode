class Solution {
  public:
    int myAtoi(string str) {
        long long int ans = 0;
        int i = 0;
        bool neg = false;

        // skip whitespace
        while (i < str.size() && isspace(str[i])) {
            i++;
        }

        // pos or neg
        if (i < str.size()) {
            if (str[i] == '-') {
                neg = true;
                i++;
            } else if (str[i] == '+') {
                i++;
            }
        }

        // convert
        while ('0' <= str[i] && str[i] <= '9') {
            ans = ans * 10 + (str[i] - '0');
            i++;
            // too big
            if (ans > INT_MAX)
                return (neg) ? INT_MIN : INT_MAX;
        }
        return (neg) ? -ans : ans;
    }
};