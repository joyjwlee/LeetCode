class Solution {
  public:
    int strStr(string haystack, string needle) {
        // edge
        if (needle.size() == 0 || haystack.compare(needle) == 0)
            return 0;
        if (haystack.size() < needle.size())
            return -1;
        // check
        for (int i = 0; i < haystack.size() - needle.size() + 1; i++)
            if (haystack.substr(i, needle.size()).compare(needle) == 0)
                return i;
        // if not returned yet
        return -1;
    }
};