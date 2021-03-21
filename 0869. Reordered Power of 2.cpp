class Solution {
  public:
    bool reorderedPowerOf2(int N) {
        /*
        3 methods to solve:
            1: 1 <= N <= 10^9, so 9! permutations, therefore can brute force
            2: count the frequency of each digit, check to see if it aligns
            3: sort by digit, generate and sort each power of 2, and compare if same
        */

        // go with method 3
        string orig = sortNum(N);
        for (int i = 0; i < 32; i++)
            if (orig == sortNum(1 << i))
                return true;
        return false;
    }

    string sortNum(int N) {
        string temp = to_string(N);
        sort(temp.begin(), temp.end());
        return temp;
    }
};