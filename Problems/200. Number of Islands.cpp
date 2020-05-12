class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
        {
            return 0;
        }

        //directional arrays
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        //numbers and queue
        int ans = 0;
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                //if we come across a starting point
                if (grid[i][j] = '1')
                {
                    ans++;
                    grid[i][j] = '0';
                    // eliminate all adjacent
                    q.push(pair(i, j));
                    while (!q.empty())
                    {
                        pair<int, int> curr = q.front();
                        q.pop();
                        int currR = curr.first;
                        int currC = curr.second;
                        for (int i = 0; i < 4; i++)
                        {
                            if (0 <= currR + dr[i] && currR + dr[i] < r)
                            {
                                if (0 <= currC + dc[i] && currC + dc[i] < c)
                                {
                                    if (grid[currR + dr[i]][currC + dc[i]] = '1')
                                    {
                                        q.push(pair(currR + dr[i], currC + dc[i]));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};