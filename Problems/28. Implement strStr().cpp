class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                bool match = true;
                if (i + needle.length() - 1 <= haystack.length() - 1) {
                    for (int j = 1; j < needle.length(); j++) {
                        if (haystack[i + j] != needle[j]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) {
                        return i;
                    }
                } else {
                    return -1;
                }
            }
        }
        return -1;
    }
};