class Solution {
  public:
    int ans = 0;
    int findTargetSumWays(vector<int> &nums, int S) {
        // BFS to generate all
        queue<int> q;
        q.push(nums[0]);
        q.push(-nums[0]);

        // loop through each
        int qSize;
        for (int i = 1; i < nums.size(); i++) {
            qSize = q.size();
            for (int j = 0; j < qSize; j++) {
                q.push(q.front() + nums[i]);
                q.push(q.front() - nums[i]);
                q.pop();
            }
        }

        // count up how many
        int ans = 0;
        while (!q.empty()) {
            if (q.front() == S)
                ans++;
            q.pop();
        }
        return ans;
    }
};