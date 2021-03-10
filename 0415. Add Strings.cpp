class Solution {
  public:
    string addStrings(string num1, string num2) {
        // variables
        string ans = "", rem;
        int carry = 0, one, two;

        // loop until one is finished
        while (num1.size() > 0 && num2.size() > 0) {
            // get last val for both
            one = num1[num1.size() - 1] - '0';
            two = num2[num2.size() - 1] - '0';
            carry += one + two;

            // update and and carry
            ans = (char)(carry % 10 + '0') + ans;
            carry /= 10;

            // remove last char for both
            num1 = num1.substr(0, num1.size() - 1);
            num2 = num2.substr(0, num2.size() - 1);
        }

        // add carry to remaining
        rem = (num1.size() != 0) ? num1 : num2;
        for (int i = rem.size() - 1; i >= 0; i--) {
            // carry can only be 0 or 1
            if (carry == 0)
                break;

            // otherwise digit is 9 or !9
            if (rem[i] == '9')
                rem[i] = '0';
            else {
                rem[i] += carry;
                carry = 0;
            }
        }

        // return depending on carry
        return (carry == 1) ? '1' + rem + ans : rem + ans;
    }
};