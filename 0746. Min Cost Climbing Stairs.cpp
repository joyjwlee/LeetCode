class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        // add two zeroes to front
        cost.insert(cost.begin(), 0);
        cost.insert(cost.begin(), 0);
        // dp through and return
        int n = cost.size();
        for (int i = 2; i < n; i++)
            cost[i] += (cost[i - 1] < cost[i - 2]) ? cost[i - 1] : cost[i - 2];
        return (cost[n - 1] < cost[n - 2]) ? cost[n - 1] : cost[n - 2];
    }
};