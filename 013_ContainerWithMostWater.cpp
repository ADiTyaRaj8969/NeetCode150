// Topic: Container With Most Water
// Description: Maximize area formed by two lines and x-axis.
// Approach: Two-pointer narrowing; maximize area by moving the smaller height pointer.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int maxArea(const vector<int>& height)
    {
        int l = 0, r = (int)height.size() - 1;
        int best = 0;
        while (l < r)
        {
            int h = min(height[l], height[r]);
            best = max(best, h * (r - l));
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return best;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{1, 8, 6, 2, 5, 4, 8, 3, 7}, {1, 1}};
    for (size_t t = 0; t < tests.size(); ++t)
    {
        cout << "Test " << (t + 1) << ": ";
        for (size_t i = 0; i < tests[t].size(); ++i)
        {
            if (i)
                cout << ",";
            cout << tests[t][i];
        }
        cout << " -> " << Solution().maxArea(tests[t]) << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
