class Solution {
  public:
    // helper to go from binary to int
    int binaryToInt(string s) {
        int num = 0, place = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1')
                num += pow(2, place);
            place++;
        }
        return num;
    }

    // helper to go from int to binary
    string intToBinary(int n) {
        // set bits
        char binaryNum[32];
        int i = 0;
        while (n > 0) {
            if (n % 2 == 0)
                binaryNum[i] = '0';
            else
                binaryNum[i] = '1';
            n = n / 2;
            i++;
        }

        // concatenate and return
        string ans = "";
        for (int j = i - 1; j >= 0; j--)
            ans += binaryNum[j];
        return ans;
    }

    string addBinary(string a, string b) {
        // get sum of both
        int sum = binaryToInt(a) + binaryToInt(b);
        // edge
        if (sum == 0)
            return "0";
        // otherwise convert sum to string
        return intToBinary(sum);
    }
};