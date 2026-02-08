// Topic: Wildcard Matching
// Description: Implement wildcard pattern matching with '?' and '*' where '?' matches any single
// char and '*' matches any sequence of chars. Approach: DP with rolling arrays or greedy
// two-pointer with backtracking. We'll use DP (O(n*m)).

#include <bits/stdc++.h>
using namespace std;

bool isMatch(const string& s, const string& p)
{
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= m; ++j)
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<string, string>> tests = {{"aa", "a"}, {"aa", "*"}, {"cb", "?b"}};

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": " << (isMatch(tests[i].first, tests[i].second) ? 1 : 0)
             << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n*m)
Space Complexity: O(n*m) (can be reduced to O(n))
*/
