class Solution {
  public:
    string addA(string s, int a) {
        string str = "";
        char c;
        for (int i = 0; i < s.size(); i++) {
            // even, just add
            if (i % 2 == 0)
                str += s[i];
            // otherwise add a
            else {
                c = s[i] + a;
                if (c > '9')
                    c -= 10;
                str += c;
            }
        }
        return str;
    }

    string rotateB(string s, int b) {
        string str = "";
        // get rightmost b
        for (int i = s.size() - b; i < s.size(); i++)
            str += s[i];
        // get first size-b
        for (int i = 0; i < s.size() - b; i++)
            str += s[i];
        return str;
    }

    string findLexSmallestString(string s, int a, int b) {
        // set to keep track all generated
        set<string> gen;

        // queue for BFS, add first
        queue<string> q;
        q.push(s);

        // generate all, BFS it, and return
        string temp, add, rotate;
        while (!q.empty()) {
            // get top
            temp = q.front();
            q.pop();

            // if already generated, skip
            if (gen.find(temp) != gen.end())
                continue;

            // otherwise insert to set, generate both, and add to queue
            gen.insert(temp);
            q.push(addA(temp, a));
            q.push(rotateB(temp, b));
        }

        return *gen.begin(); // vector<string>(gen.begin(), gen.end())[0];
    }
};