class Solution {
  public:
    int lastStoneWeight(vector<int> &stones) {
        // while we can combine, simulate
        while (stones.size() > 1) {
            // sort ascending
            sort(stones.begin(), stones.end(), greater<int>());
            if (stones[0] == stones[1])
                stones.erase(stones.begin(), stones.begin() + 2);
            else {
                stones[0] -= stones[1];
                stones.erase(stones.begin() + 1);
            }
        }
        // return ans
        return stones.size() ? stones[0] : 0;
    }
};