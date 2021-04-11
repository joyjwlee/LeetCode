class Solution {
  public:
    int secondHighest(string s) {
        // get unique characters
        set<char> u;
        for (char c : s)
            if (isdigit(c))
                u.insert(c);

        // put into vector (descending)
        vector<char> vec;
        for (auto i : u)
            vec.push_back(-i);
        sort(vec.begin(), vec.end());

        // return ans
        return (vec.size() < 2) ? -1 : -vec[1] - '0';
    }
};