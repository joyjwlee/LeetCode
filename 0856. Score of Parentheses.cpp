class Solution {
public:
    int scoreOfParentheses(string S) {
        // val to keep track
        int curr = 0;
        stack<int> vals;
        
        // loop through string
        for (char c : S) {
            // if open, add current and reset
            if (c == '(') {
                vals.push(curr);
                curr = 0;
            }
            // if closing, set curr val
            else {
                // if ()
                if (curr == 0)
                    curr = 1;
                // otherwise nested
                else
                    curr *= 2;
                // make sure stack isn't empty
                assert(!vals.empty());
                // then add to prior group
                curr += vals.top();
                vals.pop();
            }
        }
        
        // return answer
        return curr;
    }
};