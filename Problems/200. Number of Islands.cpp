class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        //Get numbers
        int numberOfIslands = 0;
        int Rows = grid.size();
        int Columns = grid[0].size();

        stack<pair<int, int>> s;

        for (int iI = 0; iI < Rows; iI++)
        {
            for (int iJ = 0; iJ < Columns; iJ++)
            {
                if (grid[iI][iJ] == '1')
                {
                    numberOfIslands++;
                    grid[iI][iJ] = '0';
                    s.push(pair(iI, iJ));
                    while (!s.empty())
                    {
                        pair rc = s.top();
                        s.pop();
                        int r = rc.first, c = rc.second;
                        if (r + 1 < Rows && grid[r + 1][c] == '1')
                        {
                            s.push(pair(r + 1, c));
                            grid[r + 1][c] = '0';
                        }
                        if (r - 1 >= 0 && grid[r - 1][c] == '1')
                        {
                            s.push(pair(r - 1, c));
                            grid[r - 1][c] = '0';
                        }
                        if (c + 1 < Columns && grid[r][c + 1] == '1')
                        {
                            s.push(pair(r, c + 1));
                            grid[r][c + 1] = '0';
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] == '1')
                        {
                            s.push(pair(r, c - 1));
                            grid[r][c - 1] = '0';
                        }
                    }
                }
            }
        }

        return numberOfIslands;
    }
};