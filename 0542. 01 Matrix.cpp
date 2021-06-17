class Solution {
  public:
    // dr dc arrays
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int bfs(int i, int j, vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        queue<vector<int>> q;
        visited[i][j] = true;
        q.push({i, j, 0});
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            if (mat[curr[0]][curr[1]] == 0)
                return curr[2];
            for (int k = 0; k < 4; k++) {
                int nextR = curr[0] + dr[k];
                int nextC = curr[1] + dc[k];
                if (0 <= nextR && nextR < n && 0 <= nextC && nextC < m && !visited[nextR][nextC]) {
                    visited[nextR][nextC] = true;
                    q.push({nextR, nextC, curr[2] + 1});
                }
            }
        }
        return -1;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        // init
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        // loop through and return ans
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[i][j] = bfs(i, j, mat);
        return ans;
    }
};

/*
class Solution {
public:
    // dr dc arrays
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    int bfs (int i, int j, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> visited (n, vector<bool>(m));
        queue<vector<int>> q;
        visited[i][j] = true;
        q.push({i, j, 0});
        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            if (mat[curr[0]][curr[1]] == 0)
                return curr[2];
            for (int k = 0; k < 4; k++) {
                int nextR = curr[0] + dr[k];
                int nextC = curr[1] + dr[k];
                if (0 <= nextR && nextR < n && 0 <= nextC && nextC < m && !visited[nextR][nextC]) {
                    visited[nextR][nextC] = true;
                    q.push({nextR, nextC, curr[2]+1});
                }
            }
        }
        return -1;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // init
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans (n, vector<int>(m));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[i][j] = bfs(i, j, mat);
        return ans;
    }
};

/////////////////////////////////////////////////

class Solution {
public:
    // dr dc arrays
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // init
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans (n, vector<int>(m));
        
        // loop through each and return ans
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // bfs
                vector<vector<bool>> visited (n, vector<bool>(m));
                queue<vector<int>> q;
                visited[i][j] = true;
                q.push({i, j, 0}); // row col dist
                while (!q.empty()) {
                    // extract curr
                    vector<int> curr = q.front();
                    q.pop();
                    // if at zero
                    if (mat[curr[0]][curr[1]] == 0) {
                        ans[i][j] = curr[2];
                        continue;
                    }
                    // otherwise add
                    for (int k = 0; k < 4; k++) {
                        int nextR = curr[0] + dr[k];
                        int nextC = curr[1] + dc[k];
                        if (0 <= nextR && nextR < n && 0 <= nextC && nextC < m && !visited[nextR][nextC]) {
                            visited[nextR][nextC] = true;
                            q.push({nextR, nextC, curr[2]+1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
*/