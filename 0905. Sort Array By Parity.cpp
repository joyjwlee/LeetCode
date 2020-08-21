class Solution {
  public:
    vector<int> sortArrayByParity(vector<int> &A) {
        vector<int> ans;
        for (int n : A)
            if (n % 2 == 0)
                ans.push_back(n);
        for (int n : A)
            if (n % 2 == 1)
                ans.push_back(n);
        return ans;
    }
};