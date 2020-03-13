class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string str = countAndSay(n - 1);
        string ans = "";
        for (int i = 0; i < str.size(); i++)
        {
            int count = 1;
            while (i < str.size() - 1 && str[i] == str[i + 1])
            {
                i++;
                count++;
            }
            ans.append(to_string(count) + str[i]);
        }
        return ans;
    }
};