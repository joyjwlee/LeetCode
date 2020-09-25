class Solution {
  public:
    // custom sort
    static bool custom(string &a, string &b) {
        return (a + b) >= (b + a);
    }

    string largestNumber(vector<int> &nums) {
        // edge case if all are zero
        int zeros = 0;
        for (int n : nums)
            if (n == 0)
                zeros++;
        if (zeros == nums.size())
            return "0";

        // batch conversion to strings
        vector<string> s;
        for (int n : nums)
            s.push_back(to_string(n));

        // custom sort
        sort(s.begin(), s.end(), custom);

        // concatenate and return
        string ans = "";
        for (string str : s)
            ans += str;
        return ans;
    }
};