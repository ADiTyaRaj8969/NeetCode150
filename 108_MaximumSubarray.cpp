// Topic: Maximum Subarray
// Description: Find contiguous subarray with largest sum.
// Approach: Kadane's algorithm (DP in O(n) time, O(1) space).

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int best = INT_MIN, cur = 0;
    for (int x : nums)
    {
        cur = max(x, cur + x);
        best = max(best, cur);
    }
    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> tests = {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, {1}, {-1, -2, -3}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": " << maxSubArray(tests[i]) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
