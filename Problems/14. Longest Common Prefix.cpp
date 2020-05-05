class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        sort(strs.begin(), strs.end());
        int count = 0;
        while (count < strs[0].size() && strs[0][count] == strs[strs.size() - 1][count])
            count++;
        return count == 0 ? "" : strs[0].substr(0, count);
    }
};