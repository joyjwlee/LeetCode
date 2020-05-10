class Solution {
  public:
    int myAtoi(string str) {
        long long ans = 0;
        sscanf(str.c_str(), "%lld", &ans);
        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;
        return (int)ans;
    }
};