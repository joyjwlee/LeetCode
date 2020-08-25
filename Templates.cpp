// BINARY SEARCH
int left = min(search_space), right = max(search_space);
while (left < right) {
    mid = left + (right - left) / 2;
    if (condition(mid))
        right = mid;
    else
        left = mid + 1;
}
return left;

// VECTOR OF DEFINED SIZE
vector<vector<int>> vec(n, vector<int>(m));

// SORT VECTOR (for ascending, remove last parameter)
sort(v.begin(), v.end(), greater<int>());

// CUSTOM SORT VECTOR (sort by second element, ascending order)
sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
});

// UNORDERED MAP
unordered_map<char, int> mp;

// DFS
// dr dc arrays
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// check for boundary
bool shouldVisit(vector<vector<char>> &grid, int i, int j) {
    if (0 <= i && i < grid.size())
        if (0 <= j && j < grid[0].size())
            return true;
    return false;
}

void DFS(vector<vector<char>> &grid, int i, int j) {
    grid[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        if (shouldVisit(grid, i + dr[k], j + dc[k]))
            DFS(grid, i + dr[k], j + dc[k]);
    }
}