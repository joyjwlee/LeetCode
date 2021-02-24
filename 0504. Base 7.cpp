class Solution {
  public:
    string convertToBase7(int num) {
        // edge
        if (num == 0)
            return "0";

        // if neg or not
        bool isNeg = false;
        if (num < 0) {
            num *= -1;
            isNeg = true;
        }

        // loop through
        string ans = "";
        while (num) {
            ans = (char)(num % 7 + '0') + ans;
            num /= 7;
        }

        // return answer
        if (isNeg)
            ans = '-' + ans;
        return ans;
    }
};