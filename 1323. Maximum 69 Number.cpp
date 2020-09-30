class Solution {
  public:
    int maximum69Number(int num) {
        // find first index of six
        string str = to_string(num);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '6') {
                str[i] = '9';
                break;
            }
        }
        // return as int
        return stoi(str);
    }
};