class Solution {
  public:
    // helper to update
    int update(int n) {
        int updt = 0;
        while (n > 0) {
            updt += (n % 10) * (n % 10);
            n /= 10;
        }
        return updt;
    }

    bool isHappy(int n) {
        // map to keep track of visited
        unordered_map<int, bool> visited;

        // loop while n isn't 1
        while (n != 1) {
            // if already visited
            if (visited[n])
                return false;
            // mark visited
            visited[n] = true;
            // update n
            n = update(n);
        }
        return true;
    }
};