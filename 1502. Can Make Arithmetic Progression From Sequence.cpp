class Solution {
  public:
    bool canMakeArithmeticProgression(vector<int> &arr) {
        // sort
        sort(arr.begin(), arr.end());

        // get diff
        int diff = arr[1] - arr[0];

        // loop and return
        for (int i = 1; i < arr.size(); i++)
            if (arr[i] - arr[i - 1] != diff)
                return false;
        return true;
    }
};