class Solution {
  public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        // map to keep track of frequency
        unordered_map<string, int> freq;

        // loop through each
        string num, domain;
        for (int i = 0; i < cpdomains.size(); i++) {
            // reset strings
            num = "", domain = "";

            // get number
            for (int j = 0; cpdomains[i][j] != ' '; j++) {
                num += cpdomains[i][j];
            }

            // get (sub)domains, extract backwards
            for (int j = cpdomains[i].size() - 1; cpdomains[i][j] != ' '; j--) {
                if (cpdomains[i][j] == '.') {
                    reverse(domain.begin(), domain.end());
                    freq[domain] += stoi(num);
                    reverse(domain.begin(), domain.end());
                }
                domain += cpdomains[i][j];
            }
            reverse(domain.begin(), domain.end());
            freq[domain] += stoi(num);
        }

        // put together, return
        vector<string> ans;
        string pair;
        for (auto i : freq) {
            pair = "";
            pair = to_string(i.second) + ' ';
            pair += i.first;
            ans.push_back(pair);
        }
        return ans;
    }
};