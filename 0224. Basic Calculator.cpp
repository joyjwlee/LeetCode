class Solution {
  public:
    int calculate(string s) {
        // stack to keep track of numbers ("sums" till now) and operators (+/-)
        stack<int> nums, op;
        int ans = 0, sign = 1;

        // loop through each char
        for (int i = 0; i < s.size(); i++) {
            // extract char
            char c = s[i];

            // whitespace
            if (c == ' ')
                continue;

            // digit
            if (isdigit(c)) {
                // extract the number
                int num = c - '0';
                while (i + 1 < s.size() && isdigit(s[i + 1])) {
                    num = num * 10 + (s[i + 1] - '0');
                    i++;
                }
                // add to answer
                ans += num * sign;
            }

            // plus/minus
            else if (c == '+')
                sign = 1;
            else if (c == '-')
                sign = -1;

            // open parentheses
            else if (c == '(') {
                // add to sums, reset
                nums.push(ans);
                ans = 0;
                // add to op, reset
                op.push(sign);
                sign = 1;
            }

            // close parentheses
            else if (c == ')') {
                // get sign since last open
                ans *= op.top();
                op.pop();
                // add anything from before
                ans += nums.top();
                nums.pop();
            }
        }

        // loop through, now return
        return ans;
    }
};