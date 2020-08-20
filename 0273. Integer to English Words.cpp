class Solution {
  public:
    // helper function
    string numtoword(int digit) {
        if (digit == 1)
            return "One";
        if (digit == 2)
            return "Two";
        if (digit == 3)
            return "Three";
        if (digit == 4)
            return "Four";
        if (digit == 5)
            return "Five";
        if (digit == 6)
            return "Six";
        if (digit == 7)
            return "Seven";
        if (digit == 8)
            return "Eight";
        if (digit == 9)
            return "Nine";
        if (digit == 10)
            return "Ten";
        if (digit == 11)
            return "Eleven";
        if (digit == 12)
            return "Twelve";
        if (digit == 13)
            return "Thirteen";
        if (digit == 14)
            return "Fourteen";
        if (digit == 15)
            return "Fifteen";
        if (digit == 16)
            return "Sixteen";
        if (digit == 17)
            return "Seventeen";
        if (digit == 18)
            return "Eighteen";
        if (digit == 19)
            return "Nineteen";
        if (digit >= 90)
            return "Ninety";
        if (digit >= 80)
            return "Eighty";
        if (digit >= 70)
            return "Seventy";
        if (digit >= 60)
            return "Sixty";
        if (digit >= 50)
            return "Fifty";
        if (digit >= 40)
            return "Forty";
        if (digit >= 30)
            return "Thirty";
        if (digit >= 20)
            return "Twenty";
        return "";
    }

    string numberToWords(int num) {
        // edge
        if (num == 0)
            return "Zero";
        // calculate
        string ans = "";
        // check the billions
        if (num / 1000000000 > 0) {
            int billions = num / 1000000000;
            ans += numberToWords(billions) + " Billion ";
            num -= billions * 1000000000;
        }
        // check millions
        if (num / 1000000 > 0) {
            int millions = num / 1000000;
            ans += numberToWords(millions) + " Million ";
            num -= millions * 1000000;
        }
        // check thousands
        if (num / 1000 > 0) {
            int thousands = num / 1000;
            ans += numberToWords(thousands) + " Thousand ";
            num -= thousands * 1000;
        }
        // check hundreds
        if (num / 100 > 0) {
            int hundreds = num / 100;
            ans += numtoword(hundreds) + " Hundred ";
            num -= hundreds * 100;
        }
        // above and below 20
        if (num > 20) {
            int tens = num / 10;
            ans += numtoword(num);
            if (num % 10 != 0) {
                num -= tens * 10;
                ans += ' ' + numtoword(num);
            }
        } else
            ans += numtoword(num);
        // final check and return
        if (ans[ans.size() - 1] == ' ')
            ans = ans.substr(0, ans.size() - 1);
        return ans;
    }
};