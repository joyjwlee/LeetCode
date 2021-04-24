class Solution {
  public:
    vector<int> constructRectangle(int area) {
        // start at sqrt and loop through
        int len = sqrt(area);
        while (area % len != 0)
            len--;
        if (len > area / len)
            return {len, area / len};
        else
            return {area / len, len};
    }
};