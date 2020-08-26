class Solution {
  public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        string concat;
        for (int i = 1; i <= n; i++) {
            concat = "";
            if (i % 3 == 0)
                concat += "Fizz";
            if (i % 5 == 0)
                concat += "Buzz";
            if (concat.compare("") != 0)
                ans.push_back(concat);
            else
                ans.push_back(to_string(i));
        }
        return ans;
    }
};