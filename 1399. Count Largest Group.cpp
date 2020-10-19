class Solution {
  public:
    int countLargestGroup(int n) {
        // up to 10^4
        vector<int> vec(40);

        // count all
        int temp, sum;
        for (int i = 1; i <= n; i++) {
            // get sum
            temp = i, sum = 0;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            vec[sum]++;
        }

        // find largest
        temp = -1;
        for (int i : vec)
            if (i > temp)
                temp = i;

        // find count and return
        int ans = 0;
        for (int i : vec)
            if (i == temp)
                ans++;
        return ans;
    }
};