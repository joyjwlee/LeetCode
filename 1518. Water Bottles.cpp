class Solution {
  public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, left = numBottles;
        while (left >= numExchange) {
            ans += (left / numExchange);
            left = (left / numExchange) + (left % numExchange);
        }
        return ans;
    }
};