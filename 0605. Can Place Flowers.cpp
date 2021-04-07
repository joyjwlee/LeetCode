class Solution {
  public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int placed = 0;

        // size 1
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0)
                placed++;
            if (placed >= n)
                return true;
            else
                return false;
        }

        // size 2
        if (flowerbed.size() == 2) {
            if (flowerbed[0] + flowerbed[1] == 0)
                placed++;
            if (placed >= n)
                return true;
            else
                return false;
        }

        // size >= 3
        if (flowerbed[0] + flowerbed[1] == 0) {
            flowerbed[0]++;
            placed++;
        }
        for (int i = 1; i < flowerbed.size() - 1; i++)
            if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
                flowerbed[i]++;
                placed++;
            }
        if (flowerbed[flowerbed.size() - 2] + flowerbed[flowerbed.size() - 1] == 0)
            placed++;
        return placed >= n;
    }
};