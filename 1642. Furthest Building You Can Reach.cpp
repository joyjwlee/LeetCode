class Solution {
  public:
    bool canReachLast(vector<int> &heights, int bricks, int ladders, int lastIdx) {
        // get distances we need to go up and sort
        vector<int> goUp;
        for (int i = 0; i < lastIdx; i++)
            if (heights[i + 1] - heights[i] > 0)
                goUp.push_back(heights[i + 1] - heights[i]);
        sort(goUp.begin(), goUp.end());

        // return true or false if we can reach last
        for (int diff : goUp) {
            // prioritize using bricks
            if (bricks >= diff)
                bricks -= diff;
            // then use ladder
            else if (ladders > 0)
                ladders--;
            // otherwise we can't reach
            else
                return false;
        }
        // made it to the end, we can reach
        return true;
    }

    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        // binary search the last one that works
        int ans = 0, l = 0, r = heights.size() - 1, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (canReachLast(heights, bricks, ladders, m)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};