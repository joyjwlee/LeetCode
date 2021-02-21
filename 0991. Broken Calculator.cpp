class Solution {
  public:
    int brokenCalc(int X, int Y) {
        // if X is greater, just diff
        if (X > Y)
            return X - Y;

        // if same, just zero
        if (X == Y)
            return 0;

        // if X is less, two cases
        if (Y % 2 == 0)
            return brokenCalc(X, Y / 2) + 1;
        else
            return brokenCalc(X, Y + 1) + 1;
    }
};

// BFS attempt -- doesn't work
/*
        // variables for BFS
        queue<pair<int, int>> q;
        map<int, bool> visited;

        // init
        q.push(make_pair(X, 0)); // curr, dist
        visited[X] = true;

        // BFS
        while (!q.empty()) {
            // extract and pop
            pair<int, int> curr = q.front();
            q.pop();

            // if found, return value
            if (curr.first == Y)
                return curr.second;

            // otherwise add to queue if not visted yet and mark as visited
            if (!visited[curr.first * 2]) {
                q.push(make_pair(curr.first * 2, curr.second + 1));
                visited[curr.first * 2] = true;
            }
            if (!visited[curr.first - 1]) {
                q.push(make_pair(curr.first - 1, curr.second + 1));
                visited[curr.first - 1] = true;
            }
        }

        // otherwise -1
        return -1;
*/