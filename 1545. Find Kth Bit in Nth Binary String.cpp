class Solution {
  public:
    char findKthBit(int n, int k) {
        string str = "0";
        int size = 0;
        for (int i = 0; i < n - 1; i++) {
            // get size before updating
            size = str.size();
            // concatenate 1
            str += '1';
            // concatenate revInv
            for (int i = size - 1; i >= 0; i--) {
                if (str[i] == '0')
                    str += '1';
                else
                    str += '0';
            }
        }
        return str[k - 1];
    }
};