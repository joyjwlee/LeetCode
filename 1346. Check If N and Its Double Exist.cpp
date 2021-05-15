class Solution {
  public:
    bool checkIfExist(vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++)
            for (int j = i + 1; j < arr.size(); j++)
                if (arr[i] * 2 == arr[j] || arr[i] == arr[j] * 2)
                    return true;
        return false;
    }

    /*
    // orig solution using set
    // init
    int zeros = 0;
    set<int> s;
    for (int i : arr) {
        if (i == 0)
            zeros++;
        if (zeros == 2)
            return true;
        s.insert(i);
    }

    // loop and return
    for (int i : arr)
        if (s.find(i*2) != s.end() && i != 0)
            return true;
    return false;
    */
};