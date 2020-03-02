class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        unordered_map<int, int> hc, vc;
        int ans = 0;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j])
                {
                    hc[i]++;
                    vc[j]++;
                    ans++;
                }

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                if (grid[i][j] && hc[i] == 1 && vc[j] == 1)
                    ans--;
        return ans;
    }
};