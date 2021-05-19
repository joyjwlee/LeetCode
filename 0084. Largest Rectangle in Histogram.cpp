class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        // init
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> s;

        // get left indices
        for (int i = 0; i < n; i++) {
            // determine limiting left index
            if (s.empty())
                left[i] = 0;
            else {
                while (!s.empty() && heights[s.top()] >= heights[i])
                    s.pop();
                if (s.empty())
                    left[i] = 0;
                else
                    left[i] = s.top() + 1;
            }
            // add curr to stack
            s.push(i);
        }

        // reset stack
        while (!s.empty())
            s.pop();

        // get right indices
        for (int i = n - 1; i >= 0; i--) {
            // determine limiting right index
            if (s.empty())
                right[i] = n - 1;
            else {
                while (!s.empty() && heights[s.top()] >= heights[i])
                    s.pop();
                if (s.empty())
                    right[i] = n - 1;
                else
                    right[i] = s.top() - 1;
            }
            // add curr to stack
            s.push(i);
        }

        // get answer and return
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, heights[i] * (right[i] - left[i] + 1));
        return ans;
    }
};