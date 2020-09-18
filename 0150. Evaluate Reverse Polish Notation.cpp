class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        // stack calculator
        stack<int> vals;
        int a, b;

        // loop and return
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                a = vals.top();
                vals.pop();
                b = vals.top();
                vals.pop();
                if (s == "+") {
                    vals.push(a + b);
                } else if (s == "-") {
                    vals.push(b - a);
                } else if (s == "*") {
                    vals.push(a * b);
                } else if (s == "/") {
                    vals.push(b / a);
                }
            } else {
                vals.push(stoi(s));
            }
        }
        return vals.top();
    }
};