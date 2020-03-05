class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> dict;
        char c;
        for (int i = 0; i < s.size(); i++)
        {
            c = s.at(i);
            if (c == '(' || c == '{' || c == '[')
            {
                dict.push_back(c);
            }
            else
            {
                if (dict.empty())
                    return false;
                if (c == ')' && dict.back() != '(')
                    return false;
                if (c == '}' && dict.back() != '{')
                    return false;
                if (c == ']' && dict.back() != '[')
                    return false;
                dict.pop_back();
            }
        }
        return dict.empty();
    }
};