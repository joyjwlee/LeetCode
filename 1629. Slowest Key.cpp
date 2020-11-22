class Solution {
  public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed) {
        // variables
        char ans = keysPressed[0];
        int max = releaseTimes[0], diff;

        // loop starting at 1 and return
        for (int i = 1; i < releaseTimes.size(); i++) {
            diff = releaseTimes[i] - releaseTimes[i - 1];
            // update if diff is larger
            if (diff > max) {
                max = diff;
                ans = ans = keysPressed[i];
            }
            // if they are the same
            else if (diff == max) {
                // update char if larger
                if (keysPressed[i] > ans)
                    ans = keysPressed[i];
            }
        }
        return ans;
    }
};