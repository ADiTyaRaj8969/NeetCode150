// Topic: Daily Temperatures
// Description: For each day, find days until a warmer temperature.
// Approach: Monotonic decreasing stack of indices.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    vector<int> dailyTemperatures(const vector<int>& T)
    {
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> st;  // indices with decreasing temperatures
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && T[i] > T[st.top()])
            {
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{73, 74, 75, 71, 69, 72, 76, 73}, {30, 40, 50, 60}};
    for (size_t i = 0; i < tests.size(); ++i)
    {
        auto out = Solution().dailyTemperatures(tests[i]);
        cout << "Test " << (i + 1) << ": ";
        for (size_t j = 0; j < out.size(); ++j)
        {
            if (j)
                cout << " ";
            cout << out[j];
        }
        cout << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
