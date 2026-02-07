// Topic: Unique Binary Search Trees
// Description: Given n, return number of structurally unique BSTs that store values 1..n.
// Approach: DP using Catalan numbers: dp[n] = sum_{i=1..n} dp[i-1]*dp[n-i].

#include <bits/stdc++.h>
using namespace std;

int numTrees(int n)
{
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int len = 1; len <= n; ++len)
    {
        for (int root = 1; root <= len; ++root)
        {
            dp[len] += dp[root - 1] * dp[len - root];
        }
    }
    return (int)dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> tests = {3, 0, 1};
    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << " (n=" << tests[i] << "): " << numTrees(tests[i]) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
