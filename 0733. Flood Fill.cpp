class Solution {
  public:
    // in bounds or not
    bool isSafe(vector<vector<int>> &image, int i, int j) {
        if (0 <= i && i < image.size())
            if (0 <= j && j < image[0].size())
                return true;
        return false;
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        // base case
        if (image[sr][sc] == newColor)
            return image;
        // dr dc arrays
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        // queue
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int orig = image[sr][sc];
        image[sr][sc] = newColor;
        // BFS
        while (!q.empty()) {
            // get front
            int currR = q.front().first, currC = q.front().second;
            q.pop();
            // push neighbors
            for (int i = 0; i < 4; i++) {
                int nextR = currR + dr[i], nextC = currC + dc[i];
                if (isSafe(image, nextR, nextC)) {
                    if (image[nextR][nextC] == orig) {
                        q.push({nextR, nextC});
                        image[nextR][nextC] = newColor;
                    }
                }
            }
        }
        return image;
    }
};