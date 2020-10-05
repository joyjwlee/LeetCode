class Solution {
  public:
    // helper for divisibility
    bool isDiv(string div, string s) {
        // by size
        if (s.size() % div.size() != 0)
            return false;
        // check each partition
        for (int i = 0; i < s.size(); i += div.size())
            if (div != s.substr(i, div.size()))
                return false;
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        // s1 is smaller, s2 larger
        string s1 = (str1.size() > str2.size()) ? str2 : str1;
        string s2 = (str1.size() > str2.size()) ? str1 : str2;

        // generate larger substring, see if divisible
        string temp = "";
        for (int i = s1.size(); i >= 1; i--) {
            temp = s1.substr(0, i);
            if (isDiv(temp, s1) && isDiv(temp, s2))
                return temp;
        }
        // none worked, so empty string
        return "";
    }
};

// misread the question:
/*
class Solution {
  public:
    string gcdOfStrings(string str1, string str2) {
        // simple bruteforce
        string sub = "", ans = "";
        for (int len = 1; len <= str1.size(); len++) {     // starting point
            for (int i = 0; i <= str1.size() - len; i++) { // ending point
                // generate substring
                sub = "";
                for (int k = i; k <= i + len - 1; k++)
                    sub += str1[k];
                // if longer and works, update
                if (str2.find(sub) != std::string::npos && sub.size() > ans.size())
                    ans = sub;
            }
        }

        // done looping, return
        return ans;
    }
};
*/