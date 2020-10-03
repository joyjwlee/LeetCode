class Solution {
  public:
    string simplifyPath(string path) {
        // parse input into stack
        stack<string> stk;
        string dir = "";
        for (int i = 0; i < path.size(); i++) {
            // skip consecutive slashes
            if (path[i] == '/') {
                while (i < path.size() && path[i] == '/')
                    i++;
                i--;
            }
            // otherwise get directory or move
            else {
                if (path[i] != '.' && path[i] != '/') {
                    dir = "";
                    while (i < path.size() && path[i] != '.' && path[i] != '/') {
                        dir += path[i];
                        i++;
                    }
                    stk.push(dir);
                    i--;
                } else {
                    dir = "";
                    while (i < path.size() && path[i] != '/') {
                        dir += path[i];
                        i++;
                    }
                    i--;
                    if (dir.size() == 2) {
                        if (!stk.empty()) {
                            stk.pop();
                        }
                    } else if (dir.size() > 2)
                        stk.push(dir);
                    // brackets cost me an hour...
                }
            }
        }

        // reverse the stack, concatenate answer, and return
        string ans = "";
        stack<string> temp;
        while (!stk.empty()) {
            temp.push(stk.top());
            stk.pop();
        }
        while (!temp.empty()) {
            ans += "/";
            ans += temp.top();
            temp.pop();
        }
        return (ans == "") ? "/" : ans;
    }
};