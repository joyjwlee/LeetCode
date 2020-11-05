class Solution {
  public:
    int findJudge(int N, vector<vector<int>> &trust) {
        // keep track of how many each trusts
        vector<int> vec(N + 1);
        for (int i = 0; i < trust.size(); i++) {
            vec[trust[i][0]]--;
            vec[trust[i][1]]++;
        }

        // loop through and find
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};