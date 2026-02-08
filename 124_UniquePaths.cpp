// Topic: Unique Paths
// Description: Number of unique paths from top-left to bottom-right in m x n grid moving only
// right/down. Approach: Combinatorics (binomial) or DP. We'll use DP with O(n) space.

#include <bits/stdc++.h>
using namespace std;

long long uniquePaths(int m, int n)
{
    vector<long long> dp(n, 1);
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j) dp[j] += dp[j - 1];
    return dp[n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> tests = {{3, 7}, {3, 2}, {1, 1}};
    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": " << uniquePaths(tests[i].first, tests[i].second) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(m*n)
Space Complexity: O(n)
*/
