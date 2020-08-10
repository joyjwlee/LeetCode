class Solution {
  public:
    int currX = 0, currY = 0, tarX, tarY;
    string ans = "";

    void moveHoriz() { // move Y (horiz)
        while (currY != tarY) {
            if (currY < tarY) {
                currY++;
                ans += 'R';
            } else {
                currY--;
                ans += 'L';
            }
        }
    }

    void moveVert() { // move X (vert)
        while (currX != tarX) {
            if (currX < tarX) {
                currX++;
                ans += 'D';
            } else {
                currX--;
                ans += 'U';
            }
        }
    }

    string alphabetBoardPath(string target) {
        for (int i = 0; i < target.size(); i++) {
            tarX = (target[i] - 97) / 5;
            tarY = (target[i] - 97) % 5;

            // direction depending on Z
            if (target[i] == 'z') {
                moveHoriz();
                moveVert();
            } else {
                moveVert();
                moveHoriz();
            }

            // since at letter, add exclamation
            ans += '!';
        }

        // return
        return ans;
    }
};