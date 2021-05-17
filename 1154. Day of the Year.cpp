class Solution {
  public:
    int dayOfYear(string date) {
        // init
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (stoi(date.substr(0, 4)) % 4 == 0)
            months[1]++;

        // find and return
        int m = stoi(date.substr(5, 2));
        int ans = stoi(date.substr(8, 2));
        for (int i = 0; i < m - 1; i++)
            ans += months[i];
        ;
        return ans;
    }
};