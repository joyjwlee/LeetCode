class Solution {
  public:
    string thousandSeparator(int n) {
        // edge
        if (n == 0)
            return "0";

        // loop through and return
        string ans = "";
        int i = 0;
        while (n) {
            // every 3, add a .
            if (i == 3) {
                ans = "." + ans;
                i = 0;
            }

            // add the digit, update vals
            ans = to_string(n % 10) + ans;
            n /= 10;
            i++;
        }
        return ans;
    }
};