class Solution
{
public:
    int myAtoi(string str)
    {
        long long n = 0;
        sscanf(str.c_str(), "%lld", &n);
        if (n > INT_MAX)
            return INT_MAX;
        if (n < INT_MIN)
            return INT_MIN;
        return (int)n;
    }
};