class Solution {
  public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        // get limits of each
        int limx = ((x == 1) ? 0 : (log(bound) / log(x))) + 1;
        int limy = ((y == 1) ? 0 : (log(bound) / log(y))) + 1;
        int pot = 0;
        // loop through bounds, add to set
        set<int> powerful;
        for (int i = 0; i < limx; i++) {
            for (int j = 0; j < limy; j++) {
                pot = pow(x, i) + pow(y, j);
                if (pot <= bound)
                    powerful.insert(pot);
            }
        }
        return vector<int>(powerful.begin(), powerful.end());
    }
};