// Topic: Trapping Rain Water
// Description: Compute trapped rainwater between elevation bars.
// Approach: Two-pointer keeping left_max and right_max to compute water in O(n) time and O(1)
// space.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
    int trap(const vector<int>& height)
    {
        int l = 0, r = (int)height.size() - 1;
        int left_max = 0, right_max = 0;
        int res = 0;
        while (l < r)
        {
            if (height[l] < height[r])
            {
                if (height[l] >= left_max)
                    left_max = height[l];
                else
                    res += left_max - height[l];
                ++l;
            }
            else
            {
                if (height[r] >= right_max)
                    right_max = height[r];
                else
                    res += right_max - height[r];
                --r;
            }
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> tests = {{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, {4, 2, 0, 3, 2, 5}};
    for (size_t t = 0; t < tests.size(); ++t)
    {
        cout << "Test " << (t + 1) << ": ";
        for (size_t i = 0; i < tests[t].size(); ++i)
        {
            if (i)
                cout << ",";
            cout << tests[t][i];
        }
        cout << " -> " << Solution().trap(tests[t]) << "\n";
    }
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
