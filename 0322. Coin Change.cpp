class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        // edge
        if (amount == 0)
            return 0;

        // variables
        queue<int> q;
        map<int, int> dist;

        // init BFS with initial vals
        for (int i : coins) {
            q.push(i);
            dist[i] = 1;
        }

        // do the BFS
        while (!q.empty()) {
            // extract current and mark as visited
            int curr = q.front();
            q.pop();
            // if we found it
            if (curr == amount)
                return dist[curr];
            // no need to go if already greater
            if (curr > amount)
                continue;
            // otherwise visit neighbors
            for (int i : coins) {
                // check for int bound
                if (curr < 0x3f3f3f3f - i) {
                    // push if we haven't visited yet and mark as visited
                    if (dist[curr + i] == 0) {
                        q.push(curr + i);
                        dist[curr + i] = dist[curr] + 1;
                    }
                }
            }
        }

        // if we reach here, then impossible
        return -1;
    }
};