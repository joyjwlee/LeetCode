class Solution {
  public:
    // vars
    int V, u, v, minVal, minIdx;
    vector<vector<int>> graph;
    vector<int> parent, key;
    vector<bool> mstSet;

    // get min key val not yet in MST
    int minKey() {
        minVal = INT_MAX;
        for (int i = 0; i < V; i++)
            if (!mstSet[i] && key[i] < minVal) {
                minVal = key[i];
                minIdx = i;
            }
        return minIdx;
    }

    int minCostConnectPoints(vector<vector<int>> &points) {
        // init
        V = points.size();
        graph.resize(V, vector<int>(V));
        parent.resize(V);
        key.resize(V, INT_MAX);
        mstSet.resize(V);

        // adjacency matrix
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                graph[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

        // start with first node
        key[0] = 0;
        parent[0] = -1;

        // MST has |V|-1 edges
        for (int cnt = 0; cnt < V - 1; cnt++) {
            // get next vertex and mark as included
            u = minKey();
            mstSet[u] = true;

            // update all nodes not in MST connected to u
            for (int v = 0; v < V; v++)
                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
        }

        // sum edges and return ans
        int ans = 0;
        for (int i = 1; i < V; i++)
            ans += graph[i][parent[i]];
        return ans;
    }
};