class Solution {
  public:
    int mySqrt(int x) {
        long int ans = 0;
        while (ans * ans < x)
            ans++;
        return (ans * ans == x) ? ans : ans - 1;
    }
};