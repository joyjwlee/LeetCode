class Solution {
  public:
    int distributeCandies(vector<int> &candyType) {
        // get all the types
        set<int> types;
        for (int i = 0; i < candyType.size(); i++)
            types.insert(candyType[i]);

        // return half of candies or number of types
        return (candyType.size() / 2 < types.size()) ? candyType.size() / 2 : types.size();
    }
};