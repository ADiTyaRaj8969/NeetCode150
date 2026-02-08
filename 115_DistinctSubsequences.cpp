// Topic: Distinct Subsequences
// Description: Count number of distinct subsequences of s which equals t.
// Approach: DP (1D rolling) with dp[0]=1 and update backwards for matches.

#include <bits/stdc++.h>
using namespace std;

long long numDistinct(const string& s, const string& t)
{
    int n = s.size(), m = t.size();
    vector<unsigned long long> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = m; j >= 1; --j)
        {
            if (s[i] == t[j - 1])
                dp[j] += dp[j - 1];
        }
    }
    return (long long)dp[m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<string, string>> tests = {
        {"rabbbit", "rabbit"},  // expect 3
        {"babgbag", "bag"},     // expect 5
        {"", ""}                // expect 1
    };

    for (int i = 0; i < (int)tests.size(); ++i)
    {
        cout << "Test " << (i + 1) << ": " << numDistinct(tests[i].first, tests[i].second) << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n*m)
Space Complexity: O(m)
*/
