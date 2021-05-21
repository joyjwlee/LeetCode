class Solution {
  public:
    // copied and modified from 84
    int largestRectangleArea(vector<int> &row) {
        // init
        int n = row.size();
        vector<int> left(n), right(n);
        stack<int> s;

        // get left indices
        for (int i = 0; i < n; i++) {
            // determine limiting left index
            if (s.empty())
                left[i] = 0;
            else {
                while (!s.empty() && row[s.top()] >= row[i])
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
                while (!s.empty() && row[s.top()] >= row[i])
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
            ans = max(ans, row[i] * (right[i] - left[i] + 1));
        return ans;
    }

    int maximalRectangle(vector<vector<char>> &matrix) {
        // edge
        if (matrix.size() == 0)
            return 0;

        // init
        int n = matrix[0].size();
        vector<int> histogram(n);
        for (int i = 0; i < n; i++)
            if (matrix[0][i] == '1')
                histogram[i] = 1;

        // loop through and return ans
        int ans = largestRectangleArea(histogram);
        for (int i = 1; i < matrix.size(); i++) {
            // update histogram
            for (int j = 0; j < n; j++)
                histogram[j] = (matrix[i][j] == '1') ? histogram[j] + 1 : 0;
            // update ans
            ans = max(ans, largestRectangleArea(histogram));
        }
        return ans;
    }
};