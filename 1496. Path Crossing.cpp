class Solution {
  public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        // set
        set<pair<int, int>> visited;
        visited.insert({x, y});
        // loop through path
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == 'N')
                y++;
            else if (path[i] == 'S')
                y--;
            else if (path[i] == 'E')
                x++;
            else if (path[i] == 'W')
                x--;
            if (visited.find({x, y}) != visited.end())
                return true;
            else
                visited.insert({x, y});
        }
        return false;
    }
};