// Topic: Largest Rectangle in Histogram
// Description: Find largest rectangular area in histogram bars.
// Approach: Monotonic stack of indices to compute nearest smaller to left/right in O(n).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int largestRectangleArea(const vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        int best = 0;
        for (int i = 0; i <= n; ++i)
        {
            int h = (i == n ? 0 : heights[i]);
            while (!st.empty() && h < heights[st.top()])
            {
                int height = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                best = max(best, height * (i - left - 1));
            }
            st.push(i);
        }
        return best;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{2, 1, 5, 6, 2, 3}, {2, 4}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": ";
        cout << Solution().largestRectangleArea(tests[i]) << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
