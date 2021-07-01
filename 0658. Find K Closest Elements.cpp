class Solution {
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        // custom sort by closest to x
        stable_sort(arr.begin(), arr.end(), [x](const auto a, const auto b) {
            return abs(a - x) < abs(b - x);
        });

        // resize for first k, sort, and return
        arr.resize(k);
        sort(arr.begin(), arr.end());
        return arr;
    }
};