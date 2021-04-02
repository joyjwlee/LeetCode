class Solution {
  public:
    bool lemonadeChange(vector<int> &bills) {
        // make it size 3
        vector<int> change(3);

        // loop through customers
        for (int i : bills) {
            if (i == 5)
                change[0]++;
            else if (i == 10) {
                if (change[0] == 0)
                    return false;
                change[0]--;
                change[1]++;
            } else {
                if (change[1] > 0 && change[0] > 0) {
                    change[1]--;
                    change[0]--;
                } else if (change[0] > 3) {
                    change[0] -= 3;
                } else {
                    return false;
                }
            }
        }

        // otherwise return true
        return true;
    }
};