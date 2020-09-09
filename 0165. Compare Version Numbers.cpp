class Solution {
  public:
    int compareVersion(string version1, string version2) {
        // loop through both, mega for loop
        int a = version1.size(), b = version2.size(), m, n;
        for (int i = 0, j = 0; i < a || j < b; i++, j++) {
            m = 0, n = 0;
            // loop through by version
            while (i < a && version1[i] != '.')
                m = m * 10 + version1[i++] - '0';
            while (j < b && version2[j] != '.')
                n = n * 10 + version2[j++] - '0';
            // return if not same
            if (m > n)
                return 1;
            if (m < n)
                return -1;
        }
        // otherwise same
        return 0;
    }
};